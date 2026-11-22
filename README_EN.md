# ROBOCON2026\-8009DOG

[![English README](https://img.shields.io/badge/English-d9d9d9)](./README_EN.md)
[![简体中文 README](https://img.shields.io/badge/简体中文-d9d9d9)](./README.md)

> Open-source repository for the quadruped robot Team 1 of Suzhou University of Technology, ROBOCON 2026 season

## Introduction

This repository archives the mechanical design, software, partial hardware, control schemes and supporting documents for the **ROBOCON 2025 quadruped robot Team 1 of Suzhou University of Technology**.

Season 2026 Achievement: **Both projects won the National Third Prize**

The main code framework is inherited from Team 2 of the previous season: [https://github.com/Childhood-zml/ROBOCON2025-8009DOG](https://github.com/Childhood-zml/ROBOCON2025-8009DOG)

Iteration updates:

- Rewrote the DT7 remote control parser based on the 2025 season implementation. Adopted 50 ms non-blocking debounce, dead zone configuration, CH4 steering lock and emergency stop to replace the original 500 ms blocking confirmation logic. Fixed sign extension for 12-bit speed/torque feedback, clamped each parameter before MIT low-level packet assembly, and unified the CAN handle input parameters.
- Added joint coil temperature monitoring (alarm and disable at 100 ℃; re-enable at 80 ℃). Implemented segmented gain for the four-phase jumping sequence. Rearranged the roll compensation signs of 8 joints according to assembly orientation. Shortened the motor task period from 3 ms to 2 ms, and built a position–velocity cascade double-loop framework (feedback wiring pending completion).
- Special note: Due to circumstances arising at a later stage, the manipulator section was not debugged and was not linked with visual navigation. Only the relevant mechanism was available for the competition task.

## Demos

Bilibili:

- [Exploded view of biomimetic quadruped robot](https://www.bilibili.com/video/BV1cCEw64E4G/?spm_id_from=333.1391.0.0&vd_source=4f07d0682bac8028161eae946482de58)
- [Motion footage of biomimetic quadruped robot](https://www.bilibili.com/video/BV1cyEw6dEKj/?spm_id_from=333.1391.0.0&vd_source=4f07d0682bac8028161eae946482de58)

Photo album live stream:

- [https://alltuu.cc/album/73a32108739142c368e1fa39230fa9c4/?menu=live](https://m/)

## Repository Directory Structure
| Directory | Description |
| --- | --- |
| `1.Hardware/` | Mechanical drawings and wiring images|
| `2.Software/` | Full lower-controller (STM32F427) code — Keil uVision project: [https://github.com/Childhood-zml/ROBOCON2026-8009DOG/blob/main/2.Software/project_8009_2026/robohorse2022/MDK-ARM/robohorse2022.uvprojx](https://github.com/Childhood-zml/ROBOCON2026-8009DOG/blob/main/2.Software/project_8009_2026/robohorse2022/MDK-ARM/robohorse2022.uvprojx) |
| `3.Document/` | Module documentation and manuals (PDF) |
| `4.Picture/` | Competition photosassets |
| `assets/` | README image assets |


## Quick Start

### Keil Project for Lower Computer

Open [`2.Software/project_8009_2026/robohorse2022/MDK-ARM/robohorse2022.uvprojx`](https://github.com/Childhood-zml/ROBOCON2026-8009DOG/blob/main/2.Software/project_8009_2026/robohorse2022/MDK-ARM/robohorse2022.uvprojx)

> 
> Recommended environment: Keil uVision5, for STM32F427, compatible with DM 8009 motor driver

## Important Notice

As the electronic control member for the 2026 season, some original design documents, debugging logs and internal notes are incomplete, and the materials may not be well-organized. We appreciate your understanding.
Feel free to raise discussions via Issues if you have any questions.

## Acknowledgements & Open-source References

Special thanks to Ningbo University of Engineering for their open-source projects:

- [https://gitee.com/Ha-WthorN/robocon-nbut](https://gitee.com/Ha-WthorN/robocon-nbut)
- [https://gitlab.com/nbutroboticslab/Competition_Projects/robocon/robocon2022](https://gitlab.com/nbutroboticslab/Competition_Projects/robocon/robocon2022)

Repository document structure references:

- [https://blog.csdn.net/weixin_52612260/article/details/134124028](https://blog.csdn.net/weixin_52612260/article/details/134124028)
- [https://blog.csdn.net/Hbutneymar/article/details/147161479](https://blog.csdn.net/Hbutneymar/article/details/147161479)

Reference materials:

- [Must-read: Introduction to LocoWiki](https://lain-database.feishu.cn/wiki/HwyJwB70niKbW7khmwlcbCH2nXb)

## License Statement

No `LICENSE` file is attached to this repository for now. Please contact the authors in advance to confirm the authorization scope before using this work in academic papers or commercial projects.

