#!/bin/bash

#################################################################
# WoeUSB Installer by joshjkk @ github
# https://github.com/joshjkk/woeusb-installer
#################################################################

usage() {
    echo -e "USAGE\n"
    echo -e "\tsudo $0 [parameters]"
    echo -e "\n\tpassing no arguments selects the default installation\n"
    echo -e "PARAMETERS\n"
    echo -e "\t[-h, --help] - shows the help menu"
    echo -e "\t[-r, --required] - installs only required dependencies"
    echo -e "\nFor more help, see https://github.com/joshjkk/woeusb-installer"
}

# Install function
# Args: 0 = default, 1 = required
install() {
    # Start message
    if [ $1 -eq 0 ];
    then
        echo "Beginning default installation..."
    elif [ $1 -eq 1 ];
    then
        echo "Beginning required installation..."
    fi

    # Update packages
    sudo apt update

    # libtool
    sudo apt install -y libtool

    # GNU gettext
    if [ $1 -eq 0 ];
    then
        sudo apt install -y gettext
    fi

    # coreutils:
    sudo apt install -y coreutils

    # autopoint
    sudo apt install -y autopoint

    # autoconf
    sudo apt install -y autoconf

    # automake
    sudo apt install -y automake

    # bison
    sudo apt install -y bison

    # util-linux, comes with the repository
    cd deps/util-linux
    sudo ./autogen.sh && sudo ./configure && sudo make
    cd ../../

    # GNU grep
    sudo apt install -y grep

    # GNU gawk
    sudo apt install -y gawk

    # GNU findutils
    sudo apt install -y findutils

    # GNU parted
    sudo apt install -y gparted

    # GNU Wget
    sudo apt install -y wget

    # dosfstools, comes with the repository
    cd deps/dosfstools
    sudo ./configure && sudo make && sudo make install
    cd ../../

    # NTFS-3G, comes with the repository
    if [ $1 -eq 0 ];
    then
        sudo apt install -y libntfs-3g883
        cd deps/ntfs-3g
        sudo ./configure && sudo make && sudo make install
        cd ../../
    fi

    # libxml
    sudo apt install -y libxml2 && sudo apt install -y libxml2-dev

    # wimlib-imagex
    sudo apt install -y wimtools 

    # wimlib, comes with the repository
    if [ $1 -eq 0 ];
    then
        cd deps/wimlib
        sudo ./configure && sudo make && sudo make install
        cd ../../
    fi
}

# Check installation type, default or required

# No args passed, 'default' installation
if [ $# -lt 1 ];
then
    install 0
# Show help menu
elif [[ ($1 = "--help" || $1 = "-h") ]];
then
    usage
# 'required' installation
elif [[ ($1 = "--required" || $1 = "-r") ]];
then
    install 1
# Unknown arg passed
else
    echo "Uknown argument '$1' passed, use '$usage' for help"
fi