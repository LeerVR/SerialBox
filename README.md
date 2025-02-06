# SerialBox

Serial Read and Write Terminal

## Using

Command Structure:

```
serialbox port speed mode
```

Example Command:

```
serialbox COM15 9600 r
```
Explanation:

```
Port: Serial port to connect to (COM followed by port number on Windows).
```

```
Speed: Speed of serial connection.
```

```
Mode: Mode for SerialBox to operate in ('r' for read and 'w' for write).
```

## Installing

### Windows

1. Download from GitHub releases ([Link](https://github.com/LeerVR/SerialBox/releases/))
2. Unzip file
3. Add to Path (Optional)

## Building

Setup prerequisites and follow platform specific building instructions.

### Prerequisites
- g++
-  windres (Windows Only)
-  ceserial ([Download](https://github.com/yan9a/serial/blob/ed8889851e4969496e0057a3d94b191e1a817613/ceserial.h))

### Windows
MakeFolders.bat can be found in BuildScripts/ and app build scripts can be found in BuildScripts/Apps/SerialBox/
1. Run MakeFolders.bat (To ensure needed folders for building are present)
2. Place ceserial.h into Lib/Global/ceserial/
3. Run SerialBox-Icon-WIN.bat
4. Run SerialBox-WIN.bat
5. Add to Path (Optional)