# c_template

Template สำหรับเริ่มโปรเจกต์ C ใหม่ใน Zed โดยไม่ต้องตั้งค่าซ้ำทุกครั้ง

## มีอะไรในนี้
- `.clangd` — บังคับ clangd ให้มองเป็น C (`-xc`), เปิด warnings, ใช้ C17
- `.clang-format` — style GNU, indent 4, ไม่ใช้ tab
- `.zed/debug.json` — debug config เรียก `make` แล้ว launch `build/prog` ผ่าน CodeLLDB
- `Makefile` — build `src/*.c` → `build/prog` พร้อม `-g` (debug symbols)
- `src/main.c` — ไฟล์ตัวอย่าง ลบ/แก้ได้เลย

## วิธีใช้กับโปรเจกต์ใหม่
```bash
cp -r ~/templates/c_template/. /path/to/new-project/
```
(เอาโฟลเดอร์นี้ไปวางไว้ที่ `~/templates/c_template` ก่อน แล้วค่อย cp ทุกครั้งที่เริ่มโปรเจกต์ใหม่)

## ต้องแก้อะไรต่อโปรเจกต์
- ถ้าชื่อ binary ไม่ใช่ `prog` หรือโฟลเดอร์ src ไม่ตรง → แก้ `Makefile` กับ `"program"` ใน `.zed/debug.json`
- ถ้าโปรเจกต์มีหลาย subfolder/header ซับซ้อน → ใช้ CMake แทน แล้วเพิ่ม `set(CMAKE_EXPORT_COMPILE_COMMANDS ON)` ใน `CMakeLists.txt` เพื่อให้ clangd เห็น `compile_commands.json` อัตโนมัติ (ไม่ต้องพึ่ง `.clangd`/Makefile ชุดนี้)
- GDB แทน CodeLLDB: เปลี่ยน `"adapter": "CodeLLDB"` เป็น `"adapter": "GDB"` ใน `.zed/debug.json` (ใช้ไม่ได้บน Apple silicon แต่โอเคบน Linux/WSL)

## วิธีคอมไพล์และรันโปรแกรม

### 1. การใช้งานผ่าน `make` (วิธีมาตรฐาน)
หากเครื่องของคุณมีคำสั่ง `make` ติดตั้งอยู่แล้ว สามารถรันคำสั่งเหล่านี้ใน Terminal:
```bash
make          # คอมไพล์โค้ดทั้งหมดใน src/ และสร้างโปรแกรมไว้ที่ build/prog
./build/prog  # รันโปรแกรม (สำหรับ Windows ใช้ .\build\prog)
make clean    # ลบโฟลเดอร์ build เพื่อล้างไฟล์ที่คอมไพล์แล้วทั้งหมด
```

---

### สำหรับผู้ใช้ Windows ที่พบปัญหาไม่รู้จักคำสั่ง `make`

หากคุณพิมพ์ `make` แล้วพบข้อผิดพลาด `The term 'make' is not recognized...` สามารถแก้ไขได้ด้วยวิธีเหล่านี้:

#### วิธีที่ A: คอมไพล์ด้วย `gcc` โดยตรง (ไม่ต้องผ่าน `make`)
หากโปรเจกต์ของคุณมีไฟล์ไม่เยอะ สามารถใช้ `gcc` คอมไพล์และรันใน PowerShell ได้โดยตรง:
```powershell
mkdir -Force build
gcc -g -Wall -Wextra -std=c17 src/main.c -o build/prog
.\build\prog
```

#### วิธีที่ B: ติดตั้ง `make` ลงใน Windows
หากต้องการใช้คำสั่ง `make` สามารถติดตั้งผ่าน Package Manager ได้เลยครับ:
* **ติดตั้งผ่าน `winget` (มีอยู่ใน Windows 10/11 อยู่แล้ว):**
  เปิด PowerShell แล้วพิมพ์:
  ```powershell
  winget install ezwinports.make
  ```
* **ติดตั้งผ่าน `Chocolatey`:**
  ```powershell
  choco install make
  ```
*(หลังจากติดตั้งเสร็จเรียบร้อยแล้ว ให้**ปิดและเปิดโปรแกรม Zed หรือ Terminal ใหม่** เพื่อเริ่มใช้งานคำสั่ง `make`)*

#### วิธีที่ C: ลองเปลี่ยนไปใช้คำสั่ง `mingw32-make`
ในชุดคอมไพล์ของ MinGW บางตัว คำสั่ง `make` จะใช้ชื่อว่า:
```powershell
mingw32-make
```
