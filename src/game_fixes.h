//game_fixes.h


#pragma once

#include "generated/default/vp_pch.h"
#include <cstdint>
#include <cstring>

static inline uint16_t VpF32ToF16Xenos(uint32_t bits) {
    const uint32_t abs_bits = bits & 0x7FFFFFFF;

    float f;
    std::memcpy(&f, &abs_bits, sizeof(f));

    const uint8_t e =
        (f != f || f > 65504.0f)
            ? 0xFF
            : uint8_t((bits & 0x7F800000) >> 23);

    const uint16_t m =
        e != 0xFF ? uint16_t((bits & 0x7FE000) >> 13) : 0;

    const uint16_t h =
        e != 0xFF
            ? (e > 0x70
                   ? uint16_t(((e - 0x70) << 10) + m)
                   : (0x71 - e > 31
                          ? uint16_t(0)
                          : uint16_t((0x400 + m) >> (0x71 - e))))
            : uint16_t(0x7FFF);

    return uint16_t(h | ((bits & 0x80000000) >> 16));
}

void VpFixVpkd3d128Float16x4(
    PPCVRegister& v0,
    PPCFPSCRRegister& fpscr) {

    fpscr.enableFlushMode();

    // Снимок исходных lane до перезаписи регистра.
    const uint32_t x = v0.u32[3];
    const uint32_t y = v0.u32[2];
    const uint32_t z = v0.u32[1];
    const uint32_t w = v0.u32[0];

    v0.u16[7] = VpF32ToF16Xenos(x);
    v0.u16[6] = VpF32ToF16Xenos(y);
    v0.u16[5] = VpF32ToF16Xenos(z);
    v0.u16[4] = VpF32ToF16Xenos(w);
}
