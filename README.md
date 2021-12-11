# Group 9 Project - An appointment manager program
An appointment manager program for creating/deleting/updating appointments with an easy user interface. <br>
---
**Version - 1.0**

## Features
- [x] Create a new appointment.
- [x] Delete an existing appointment.
- [x] Update an existing appointment.
- [x] Display a single appointment.
- [x] Display a range of appointments.
- [x] Display all appointments.
- [x] Save accumulated data to disk.
- [x] Load accumulated data from disk.

## Build Instructions
Simply run the bundled `.sln` file and click **F5** or *Debug & Build* in visual studio.
Or
If you have **C++ Build Tools** on *Windows* then build the files by opening a developer command prompt and going to the project directory then typing the following:
``` ps
cl *.c
./main.exe
```
If running **GCC/Clang** on *Mac/Linux* then type the following.<br>
**GCC**:
``` bash
gcc *.c -o main
./main
```
**Clang**:
``` bash
clang *.c -o main
./main
```

## Contributors
`Ali-Noureddine` - Added Add function
				 - Added Delete function
				 - Added Edit function
				 - Added Search function
				 - Added List function<br>
`Hunter-Oswald` - <br>
`Mostafa-Elbasiouny` - Enhanced the menu, added range search and other quality changes/fixes including input validation.<br>
