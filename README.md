# Viva Piñata Recompiled

**An experimental PC port of Viva Piñata (Xbox 360), with Nintendo Switch as a long-term target.**

![Status](https://img.shields.io/badge/status-working%20beta-blue)
![Version](https://img.shields.io/badge/version-0.1.0--beta-orange)
![Platform](https://img.shields.io/badge/current%20platform-PC-lightgrey)
![Future target](https://img.shields.io/badge/future%20target-Nintendo%20Switch-red)

## Getting Started

### Requirements

- A Windows PC.
- A copy of the original Xbox 360 version of *Viva Piñata*.
- The game's data files extracted from your own copy.
- The files provided in the project release.

### Setup and Launch

1. Download and extract the project release.
2. Extract the game data from your own Xbox 360 copy of *Viva Piñata*.
3. Open `run.bat` in a text editor.
4. Locate the `--game_data_root` argument and change its path to the directory containing your extracted game data.

   Example:

   ```bat
   vp.exe --game_data_root "D:\VivaPinata" --d3d12_debug --d3d12_break_on_error --gpu_plugin="xenos" --fullscreen=false
   ```

   In this example, `D:\VivaPinata` is the directory containing your game data. Replace it with the actual path on your system.

5. Save `run.bat` and launch the game by double-clicking it.

**Important:** The path shown above is only an example. Make sure it points to the correct directory containing your extracted game data.

### Troubleshooting

- **Game data not found:** Check the `--game_data_root` path in `run.bat`.
- **Startup or graphics issues:** Check the release notes and report reproducible issues with relevant logs and system information.

## Game Data and Copyright Notice

**This project does not distribute the original game data.**

No original *Viva Piñata* game assets, extracted Xbox 360 game data, or copyrighted game content are intentionally included in this project release.

Users must obtain their own copy of the original game and prepare the required game data themselves.

All trademarks, game assets, and intellectual property associated with *Viva Piñata* belong to their respective owners.

This is an independent, non-commercial research and fan project. It is not affiliated with or endorsed by Microsoft, Rare, Nintendo, or the original game's publishers.

Users are responsible for ensuring that their use of game data complies with applicable laws.

## Overview

**Viva Piñata Recompiled** is an experimental project focused on bringing the original Xbox 360 version of *Viva Piñata* to modern hardware through recompilation, with the long-term goal of exploring a potential Nintendo Switch port.

The project uses [ReXGlue](https://github.com/) to recompile the original Xbox 360 executable into native C++ code for a PC build. The current release is a working, actively tested beta.

This is both a game preservation and a learning project: an opportunity to explore Xbox 360 software, platform SDKs, graphics APIs, shader pipelines, and the challenges of porting a game between different hardware architectures.

## Current Status

**Version: 0.1.0-beta**

- Working PC build.
- Actively tested, with ongoing compatibility fixes.
- Recompiled game code generated using ReXGlue.
- Graphics and rendering compatibility work in progress.
- Renderer improvements and shader development planned.
- Nintendo Switch port is a long-term goal, not a currently supported platform.

This is an early beta. Rendering issues, graphical glitches, crashes, and other compatibility problems may occur.

## Roadmap

### Phase 1 — PC recompilation

- [x] Produce a working PC build.
- [x] Establish a reproducible testing workflow.
- [x] Begin investigating graphics and compatibility issues.
- [ ] Improve stability and game compatibility.
- [ ] Document known issues and fixes.

### Phase 2 — Graphics and rendering

- [ ] Investigate and improve the rendering pipeline.
- [ ] Implement or adapt shaders where necessary.
- [ ] Fix remaining graphical issues.
- [ ] Improve compatibility with modern PC graphics hardware.

### Phase 3 — Nintendo Switch research

- [ ] Study the target platform's hardware and SDK.
- [ ] Evaluate the feasibility of adapting the renderer.
- [ ] Investigate platform-specific memory, graphics, and performance requirements.
- [ ] Explore a potential native port, subject to technical and legal constraints.

The roadmap is experimental and may change as development progresses.

## Why This Project?

The original *Viva Piñata* is a distinctive game that deserves to remain accessible on modern hardware.

Beyond the game itself, this project is an opportunity to learn by doing: understanding a real-world codebase, studying low-level graphics behavior, debugging recompilation issues, and exploring how software designed for one console architecture can be adapted to another.

One of the long-term motivations is the possibility of playing *Viva Piñata* on a portable device. The Nintendo Switch is an aspirational target, with no promise of a working port or a specific release date.

## Technology

- **Original platform:** Xbox 360
- **Current target:** PC (Windows)
- **Recompilation:** ReXGlue
- **Implementation:** Generated C++ and native PC build toolchain
- **Graphics:** Current renderer under investigation; renderer changes and shader work planned
- **Future research target:** Nintendo Switch

## Getting Started

Download the appropriate release from the **[Releases](../../releases)** page.

1. Read the release notes and any included setup instructions.
2. Prepare the required game data from your own legally obtained copy.
3. Place files in the locations specified by the release documentation.
4. Launch the build using the included instructions.

Requirements and setup details may change between beta releases. Check the notes for the specific version you are using.

**Important:** The release may require original game files that are not included in this repository.

## Contributing

Technical feedback, reproducible bug reports, and research into graphics compatibility are welcome.

When reporting an issue, please include:

- The release version.
- Your operating system and hardware.
- Steps to reproduce the problem.
- Relevant logs or error messages.
- Screenshots of graphical issues, where applicable.

Contributions related to stability, rendering, shader development, documentation, and platform research are especially useful.

## Disclaimer

This is an independent, experimental fan project. It is not affiliated with, endorsed by, or sponsored by Microsoft, Rare, Nintendo, or the original game's publishers or developers.

*Viva Piñata* and all related trademarks and intellectual property belong to their respective owners.

This project does not aim to distribute copyrighted game assets or original game binaries. Users are responsible for obtaining and using game files in accordance with applicable laws.

Nintendo Switch support is a research goal only. No official or unofficial Switch release is promised.

## Credits
- **thex aka StarVision** - one man army :) (If you want to join this project, we are happy to see you.)
- **ReXGlue** — recompilation tooling.
- **Rare / Microsoft** — original *Viva Piñata* game.
- **The homebrew and game preservation communities** — technical inspiration and shared knowledge.

---

*Made for learning, experimentation, game preservation, and the dream of taking a little garden full of Piñatas on the go.*
