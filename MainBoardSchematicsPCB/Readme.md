
# Little Green House – Open Hardware PCB Project

This repository contains the complete KiCad project files for the **Little Green House (LG)**, an open-source smart greenhouse controller. This PCB is designed to control and automate indoor plant care with features such as real-time clock, peristaltic pump, environmental sensors, and a user interface (OLED + buttons).

## 📁 Files Overview

### 🖥️ Design Files (KiCad)
- `LittleGreenHouse.kicad_pcb`: Main PCB layout
- `LittleGreenHouse.sch`: Main schematic
- `LittleGreenHouse.pro`: Project settings
- `LittleGreenHouse-cache.lib`, `LittleGreenHouse-cache.dcm`: Cached libraries
- `LittleGreenHouse-rescue.lib`, `LittleGreenHouse-rescue.dcm`: Rescued components
- `sym-lib-table`: Symbol library table

### 🧾 BOM & Netlist
- `LittleGreenHouse.csv`: Bill of Materials (BOM)
- `LittleGreenHouse.net`: Netlist
- `LittleGreenHouse.xml`: XML export for online BOM tools

### 📐 Mechanical & Fabrication Files
- `LittleGreenHouse-B_Cu.dxf`, `.svg`, `.pdf`: Bottom copper layer
- `LittleGreenHouse-F_SilkS.pdf`: Front silkscreen layer
- `LittleGreenHouse-Edge_Cuts.dxf`, `.svg`: Edge cuts for fabrication
- `LittleGreenHouseCarbide.c2d`: Carbide Create file for CNC routing

### 📄 Documentation
- `LittleGreenHouse.pdf`: Full schematic and layout export
- `LittleGreenHouse_SVG.svg`: Combined PCB graphic

### 🗃️ Backups
- `*.bak` and `*.bck` files: Automatic KiCad backups of schematic and PCB files

## 🔧 How to Use

1. Open the project in **KiCad** (version 6 or later recommended).
2. Modify or review the schematic and PCB as needed.
3. Export Gerbers or use the included files for manufacturing.
4. Refer to the [main documentation repository](https://github.com/...) for firmware and assembly instructions.

## 📜 License

This hardware is licensed under the **CERN-OHL-S v2** (or other you prefer). You are free to use, modify, and manufacture it under open hardware principles. Please refer to the `LICENSE` file for details.

## 🌱 About

This board is part of the [Little Green House project](https://github.com/...), an open-source smart greenhouse developed by **Mighty Tronics**.
