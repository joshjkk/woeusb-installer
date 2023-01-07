# WoeUSB Installer

### A dependency installer script for [WoeUSB](https://github.com/WoeUSB/WoeUSB) on [Debian GNU/Linux](https://en.wikipedia.org/wiki/Debian) systems.

![GitHub file size in bytes](https://img.shields.io/github/size/joshjkk/woeusb-installer/install.sh) ![GitHub](https://img.shields.io/github/license/joshjkk/woeusb-installer) ![GitHub release (latest by date)](https://img.shields.io/github/v/release/joshjkk/woeusb-installer)

Hunting each prerequisite for WoeUSB has always been a pain for me, and probably others, so I decided to make a script to do it for you.

## Usage

``` bash
sudo ./install.sh [args]
```

Where [args] are optional arguments.

### Required Installation (recommended)

The default installation may give errors, whereas the required installation doesn't but both work with WoeUSB.

``` bash
sudo ./install.sh -r
```

### Full Installation

``` bash
sudo ./install.sh
```

This installation is not recommended as it may give errors installing certain dependencies, which is entirely dependant on your system.

### Arguments

- ```--help```, ```-h``` - Show the help menu.
- ```--required```, ```-r``` - Choose the required installation method.

## Dependencies

*This is the list of dependencies that WoeUSB Installer will install.*

The following are the dependencies that WoeUSB requires, in one way or another.  Refer [the wiki](https://github.com/WoeUSB/WoeUSB/wiki/Dependencies) for distro-specific information.

### Required

WoeUSB will not be able to function without these software installed in their proper locations:

* [GNU Bash](https://www.gnu.org/software/bash/)  
  For interpreting and executing the program logic  
  _Requires >= 4.3_
  > Pre-installed
* [The GNU Core Utilities(Coreutils)](https://www.gnu.org/software/coreutils/)  
  For common Unix utilities necessary for basic operations
* [util-linux](https://github.com/karelzak/util-linux)  
  For low-level utilities interacting with storage devices, etc
* [GNU Grep](https://www.gnu.org/software/grep/) and [Gawk](https://www.gnu.org/software/gawk/)  
  For parsing necessary information out from a command output
* [The GNU Find Utilities](https://www.gnu.org/software/findutils/)  
  For enumerating files required for operation
* [GNU GRUB](https://www.gnu.org/software/grub/)  
  For installing the bootstrap code used in a Legacy PC boot  
  We specifically requires modules of the i386-pc architecture, for Debian-based distributions these are provided via the grub-pc-bin package
  > Pre-installed
* [GNU Parted](https://www.gnu.org/software/parted/)  
  For manipulating disk partition table and partitions
* [GNU Wget](https://www.gnu.org/software/wget/)  
  For acquiring [Pete Batard](https://pete.akeo.ie/)'s [UEFI:NTFS](https://github.com/pbatard/uefi-ntfs) UEFI bootloader
* [dosfstools](https://github.com/dosfstools/dosfstools)  
  For creating FAT filesystem in `--device` creation method
* [NTFS-3G](https://www.tuxera.com/community/open-source-ntfs-3g/)  
  For creating NTFS filesystem in `--device` creation method
* [wimlib](https://wimlib.net/)  
  For splitting install.wim Windows Imaging (WIM) archive so that archives over 4GiB can be fit in an FAT32 filesystem

### Optional

Without the following dependencies WoeUSB will still able to run, but some functionalities will be unavailable:

* [p7zip](https://sourceforge.net/projects/p7zip/)  
  For workaround the problem where the Windows 7 installation media doesn't ship their UEFI bootloader in the proper location
* [Pete Batard](https://pete.akeo.ie/)'s [UEFI:NTFS](https://github.com/pbatard/uefi-ntfs) UEFI bootloader  
  For supporting NTFS filesystems in the target USB key
* [GNU gettext](https://www.gnu.org/software/gettext/)  
  For supporting message internationalization(I18N)

## License

WoeUSB Installer is licensed under the Apache License 2.0.
