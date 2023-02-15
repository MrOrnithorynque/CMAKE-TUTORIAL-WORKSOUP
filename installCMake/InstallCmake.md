# CMAKE-TUTORIAL-WORKSOUP
## CMAKE Installation

### Linux
Here is a brief guide to installing version 3.26 of CMake on a Linux system.

#### If you don't have CMake

If you have not installed CMake on your system, you can follow the instructions below to install it.

#### If you do have CMake

If you do have cmake but it is a version older than 3.20, remote it and you can follow the instructions below to upgrade it.

To check the version of CMake that you have installed, run the following command:

```bash
cmake --version
```

To remove CMake from your system, run the following command:

```bash
sudo apt-get remove cmake
```
#### To install CMake*

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
wget https://github.com/Kitware/CMake/releases/download/v3.26.0-rc2/cmake-3.26.0-rc2.tar.gz
```

Extract the archive by running the following command:

```bash
tar xzf cmake-3.26.0-rc2.tar.gz
```

Change to the extracted directory:


```bash
cd cmake-3.26.0-rc2
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

### Windows
Here is a brief guide to installing version 3.26 of CMake on a Windows system:

Download the CMake installer from the official website by visiting the following link: https://cmake.org/download/

On the download page, select the appropriate version of CMake for your system (i.e., 32-bit or 64-bit).

Once the download is complete, run the installer and follow the instructions to install CMake on your system.

During the installation process, make sure to select the "Add CMake to the system PATH for all users" option. This will allow you to run CMake from the command prompt.

After the installation is complete, open a command prompt and run the following command to verify that CMake has been installed:

```bash
cmake --version
```

This should output the version number of CMake that you just installed.

That's it! You should now have CMake version 3.26.0 installed on your Windows system.

### MacOS
Here is a brief guide to installing version 3.26 of CMake on a macOS system:

Open a terminal window and install the Xcode command-line tools by running the following command:

```bash
xcode-select --install
```

Install Homebrew, a package manager for macOS, by running the following command:

```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

Use Homebrew to install CMake by running the following command:

```brash
brew install cmake@3.26
```

After the installation is complete, run the following command to verify that CMake has been installed:

```bash
cmake --version
```

This should output the version number of CMake that you just installed.

That's it! You should now have CMake version 3.26.0 installed on your macOS system.





