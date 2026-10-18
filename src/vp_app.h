#pragma once

#include <rex/rex_app.h>
#include <windows.h> // Подключаем Win32 API

class VpApp : public rex::ReXApp {
 public:
  using rex::ReXApp::ReXApp;

  static std::unique_ptr<rex::ui::WindowedApp> Create(
      rex::ui::WindowedAppContext& ctx) {
    return std::unique_ptr<VpApp>(new VpApp(ctx, "vp", PPCImageConfig));
  }

  void OnCreateDialogs(rex::ui::ImGuiDrawer* drawer) override {
    rex::ReXApp::OnCreateDialogs(drawer);

    // Динамически берем адрес функции инвалидации памяти прямо из скомпилированной DLL
    static HMODULE hGpuDll = GetModuleHandleA("rexgpu-xenos.dll");
    if (hGpuDll) {
        // Ищем экспортированную функцию (имя манглится компилятором, но базовый сброс часто доступен)
        typedef void(*InvalidateFunc)();
        static InvalidateFunc pInvalidate = (InvalidateFunc)GetProcAddress(hGpuDll, "InvalidateGpuMemory");
        
        if (pInvalidate) {
            pInvalidate(); // Жесткий сброс кэша прямо внутри DLL!
        }
    }
  }
};
