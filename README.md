# WoeUSB Installer

A dependency installer script for [WoeUSB](https://github.com/WoeUSB/WoeUSB) on [Debian GNU/Linux](https://en.wikipedia.org/wiki/Debian) systems.

![GitHub release (latest by date)](https://img.shields.io/github/v/release/joshjkk/woeusb-installer) ![GitHub file size in bytes](https://img.shields.io/github/size/joshjkk/woeusb-installer/installer.sh)

## About

[WoeUSB](https://github.com/WoeUSB/WoeUSB) is a Microsoft Windows® USB installation media preparer for GNU+Linux, [WoeUSB Installer](https://github.com/joshjkk/woeusb-installer) is a script that installs all the dependencies needed to run WoeUSB on [Debian GNU/Linux](https://en.wikipedia.org/wiki/Debian).

This script was created because from my experience, it takes ages to install all the dependencies, and it would be a big help for myself and maybe others if it was all automated.

## Usage

### Give Execution Permissions

You won't be able to run the script if you don't give the script permissions to execute:

``` bash
chmod +x ./installer.sh
```

### **Default Installation**

*(required & optional dependencies, may cause errors)*

``` bash
sudo ./installer.sh
```

### **Required Dependencies Only**

Parameter: ```--required``` ```-r```

Example:

``` bash
sudo ./installer.sh -r
```

## Dependencies

*This is the list of dependencies that WoeUSB Installer will install.*

The following are the dependencies that WoeUSB requires, in one way or another.  Refer [the wiki](https://github.com/WoeUSB/WoeUSB/wiki/Dependencies) for distro-specific information.

### **Required**

WoeUSB will not be able to function without these software installed in their proper locations:

* [GNU Bash](https://www.gnu.org/software/bash/)  
  For interpreting and executing the program logic  
  _Requires >= 4.3_
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

### **Optional**

Without the following dependencies WoeUSB will still able to run, but some functionalities will be unavailable:

* [p7zip](https://sourceforge.net/projects/p7zip/)  
  For workaround the problem where the Windows 7 installation media doesn't ship their UEFI bootloader in the proper location
* [Pete Batard](https://pete.akeo.ie/)'s [UEFI:NTFS](https://github.com/pbatard/uefi-ntfs) UEFI bootloader  
  For supporting NTFS filesystems in the target USB key
* [GNU gettext](https://www.gnu.org/software/gettext/)  
  For supporting message internationalization(I18N)

## License

WoeUSB Installer is licensed under the Apache License 2.0.
