# CMAKE-TUTORIAL-WORKSOUP
## Installation

#### If you don't have CMake
If you have not installed CMake on your system, you can follow the instructions below to install it.

#### If you do have CMake

If you do have cmake but it is a version older than 3.20, you can follow the instructions below to upgrade it.

To check the version of CMake that you have installed, run the following command:

```bash
cmake --version
```

To remove CMake from your system, run the following command:

```bash
sudo apt-get remove cmake
```

### Linux
Here is a brief guide to installing version 3.26 of CMake on a Linux system.
Open a terminal window and enter the following command to update the package list:

```bash
sudo apt-get update
```

Install the necessary dependencies for building CMake:

```bash
sudo apt-get install -y build-essential libssl-dev
```

Download the CMake source code archive from the official website using the following command:

```bash
wget https://github.com/Kitware/CMake/releases/download/v3.26.0-rc2/cmake-3.26.0-rc2-linux-x86_64.tar.gz
```

Extract the archive by running the following command:

```bash
tar xzf cmake-3.26.0.tar.gz
```

Change to the extracted directory:


```bash
cd cmake-3.26.0
```

Then configure the build process by running the following command:


```bash
./bootstrap
```

Build and install CMake by running the following commands:

```bash
make

sudo make install
```

Verify that CMake has been installed by running the following command:

```bash
cmake --version
```

This should output the version number of CMake that you just installed.

That's it! You should now have CMake version 3.26.0 installed on your Linux system.
