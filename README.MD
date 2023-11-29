# Windows Ring 0 API Demo

Just a simple project showing the use of the WinRing0 API on Windows 11 64-bit, compiled with Visual Studio 2022.

### How to build

#### 1 - Install requirements:

* Visual Studio 2022 (Version 17.8.1)
* Windows 11 SDK (Version 10.0.22621.0)
* Windows WDK (Version 10.0.22621.2428)

More details about installation in this [Link 🔗](https://learn.microsoft.com/en-us/windows-hardware/drivers/download-the-wdk#download-icon-step-2-install-sdk)

#### 2 - Clone this repository and build

Git clone this project in a folder of your choice, go to the Source folder and open the .sln file, in Visual Studio press Ctrl+Shift+B, this will compile the project without running, it just generates the executable.

> git clone https://github.com/ali90taz/RingZero

#### 3 - Open a PowerShell or CMD window with adminstrator privileges and run

If you compiled correctly, the binary will be in the Bin folder with the name rz.exe, always open it with administrator privileges.

### Help and reference

In the Doc folder there is a help file (.chm) detailing the use of the WinRing0 API in detail, take a look.

### Disclaimer

By using this API you will have direct access to the computer hardware and the operating system kernel, there are real possibilities of damaging the hardware, losing data and freezing the system, use with caution.

### Copyrights

2007-2009 hiyohiyo <hiyohiyo@crystalmark.info> - Original Author
<br>
2019-2023 GermanAizek <GermanAizek@yandex.ru> - Current Maintainer