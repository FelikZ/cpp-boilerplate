
## C++ multiplatform test

You need CMake installed to build a project.

Make sure that after git clone, you do:
```
git submodule update --init
```

## Build

All necessary packages other then Standard Libs, will be downloaded and build through CMake.

### All

* Install CMake 3.10+
* Install conan `pip install conan`

### Windows

Tested with "Visual Studio 15 2017 Win64 v15.6.3" but can be build with others too.

**[deprecated]** **[optional]** if you want to **build** TBB, install [make](https://sourceforge.net/projects/gnuwin32/files/make/3.81/make-3.81.exe/download), which is required by TBB.

### OSX

```
# install Command Line Tools
xcode-select --install
```

### Linux

You need g++ 7.1 to support c++17 standard and <variant>

```
# ubuntu
#wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | sudo apt-key add -
#sudo apt-add-repository "deb http://apt.llvm.org/xenial/ llvm-toolchain-xenial-5.0 main"
#sudo apt-get update
#sudo apt-get install -y clang-5.0
#sudo update-alternatives --install /usr/bin/clang++ clang++ /usr/bin/clang++-5.0 1000
#sudo update-alternatives --install /usr/bin/clang clang /usr/bin/clang-5.0 1000
#sudo update-alternatives --config clang
#sudo update-alternatives --config clang++
#sudo update-alternatives --install /usr/bin/cc cc /usr/bin/clang 1000

sudo add-apt-repository ppa:jonathonf/gcc-7.1
sudo apt-get update
sudo apt-get install -y gcc-7 g++-7
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-7 1000
sudo update-alternatives --install /usr/bin/c++ c++ /usr/bin/g++ 1000
```
