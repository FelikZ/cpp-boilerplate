
## C++ multiplatform test

You need CMake installed to build a project.

Make sure that after git clone, you do:
```
git submodule update --init
```

## Build

All necessary packages other then Standard Libs, will be downloaded and build through CMake.

### All

Install CMake 3.8+

### Windows

Tested with "Visual Studio 15 2017 Win64" but can be build with others too.

**[optional]** if you want to **build** TBB, install [make](https://sourceforge.net/projects/gnuwin32/files/make/3.81/make-3.81.exe/download), which is required by TBB.

### OSX

```
# install Command Line Tools
xcode-select --install
```

### Linux

```
apt-get install clang -y
# make Clang default compiler
sudo update-alternatives --config c++

# yum install clang -y
```
