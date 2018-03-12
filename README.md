
## C++ multiplatform test

You need CMake installed to build a project.

Make sure that after git clone, you do:
```
git submodule update --init
```

## Windows

1. Download [TBB](https://github.com/01org/tbb/releases). (tested version 2018_U2)
2. Put it under `%userprofile%/lib`
3. Update your env accordingly:
```
TBB_INSTALL_DIR="C:/Users/Home/lib/tbb",
TBB_BINARY_DIR="C:/Users/Home/lib/tbb/bin/intel64/vc14",
LIBRARY_PATH="C:/Users/Home/lib/tbb/lib/intel64/vc14"
```
4. (or for VSCode CMake tools) Update `~/.vscode/settings.json` accordingly:
```
    "cmake.windows.environment": {
        "TBB_INSTALL_DIR": "C:/Users/Home/lib/tbb",
        "TBB_BINARY_DIR": "C:/Users/Home/lib/tbb/bin/intel64/vc14",
        "LIBRARY_PATH": "C:/Users/Home/lib/tbb/lib/intel64/vc14"
    },
```

## OSX

```
brew install tbb
```
## Ubuntu

```
sudo apt-get install libtbb-dev
```