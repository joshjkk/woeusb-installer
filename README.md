# WoeUSB Installer

A dependency installer script for [WoeUSB](https://github.com/WoeUSB/WoeUSB) on [Debian GNU/Linux](https://en.wikipedia.org/wiki/Debian) systems.

![GitHub release (latest by date)](https://img.shields.io/github/v/release/joshjkk/woeusb-installer) ![GitHub file size in bytes](https://img.shields.io/github/size/joshjkk/woeusb-installer/installer.sh)

## About

[WoeUSB](https://github.com/WoeUSB/WoeUSB) is a Microsoft Windows® USB installation media preparer for GNU+Linux, [WoeUSB Installer](https://github.com/joshjkk/woeusb-installer) is a script that installs all the dependencies needed to run WoeUSB on [Debian GNU/Linux](https://en.wikipedia.org/wiki/Debian).

This script was created because from my experience, it takes ages to install all the dependencies, and it would be a big help for myself and maybe others if it was all automated.

## Build

### Prerequisites

#### ncurses

``` bash
sudo apt install libncurses5-dev libncursesw5-dev
```

#### make

``` bash
$ sudo apt install build-essential
```

### Building the ```.exe``` File

``` bash
sudo make woeusb_installer
```

## Installation

To install WoeUSB Installer, clone the repo and follow the Build instructions:

``` bash
git clone https://github.com/joshjkk/woeusb-installer.git && cd woeusb_installer
```

While inside ```woeusb_installer```:

``` bash
sudo make woeusb_installer
```

```woeusb_installer.exe``` will be found in the ```./bin/woeusb_installer.exe```.

## Usage

``` bash
sudo ./woeusb_installer [args]
```

Where args are optional arguments.

### Args

- ```--version```, ```-v``` - Show the current installed version of WoeUSB Installer
- ```--help```, ```-h``` - Show the help menu

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
