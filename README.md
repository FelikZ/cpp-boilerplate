
## C++ multiplatform test

You need CMake installed to build a project.

Make sure that after git clone, you do:
```
git submodule update --init
```

## Build

All necessary packages other then Standard Libs, will be downloaded and build through CMake.

### Windows

Tested with "Visual Studio 15 2017 Win64" but can be build with others too.

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
