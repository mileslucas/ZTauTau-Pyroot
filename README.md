# ZTT

This repository contains the data files and appropriate Root macros for the
Z->Tau-Tau lab in Physics 322L at Iowa State University

## Prerequisites
The prerequisites for this lab are [Cern's Root](https://root.cern.ch/).

The instructions provided at Cern's site are comprehensive in downloading, building, and setting up Root correctly. I strongly recommend using [their build instructions](https://root.cern.ch/building-root). Here is the brief quick-start.

1. Install prerequisites (If this is not your package manager, see [here](https://root.cern.ch/build-prerequisites).)
```
sudo apt-get install git dpkg-dev cmake g++ gcc binutils libx11-dev libxpm-dev \
libxft-dev libxext-dev
```
2. Download Root
```
git clone http://root.cern.ch/git/root.git ~/root-src
```
3. Setup Root path
```
mkdir ~/root
cd ~/root
```
4. Run cmake. For any issues, check [here](https://root.cern.ch/building-root).
```
cmake ~/root-src
```
5. Build root (this will take a long time)
```
cmake --build . --
```
6. Setup use in the shell and start Root shell
```
source ~/root/bin/thisroot.sh
root
```
7. If Root starts correctly, clean up
```
rm -r ~/root-src
```

## Usage
To use this code is simple, to run a Root macro, simply use the x command like
this
```
root -x simulation.cpp
```
or
```
root
root [0] .x simulation.cpp
```

Root macros are meant to be tinkered with. Feel free to go into the cpp file and edit the macro! It is written in c++, so take a quick primer so you can feel comfortable with the syntax. Otherwise, most everything is commented for your use.
