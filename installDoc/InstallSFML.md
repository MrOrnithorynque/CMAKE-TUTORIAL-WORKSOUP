*CMAKE-TUTORIAL-WORKSOUP*
# Installing SFML on Linux, Windows, and macOS

SFML (Simple and Fast Multimedia Library) is a cross-platform software development library designed to provide a simple interface for working with multimedia.

It can be used for developing video games, multimedia applications, and other graphical applications. In this tutorial, we will walk through the process of installing SFML on Linux, Windows, and macOS.

## Prerequisites

Before we begin, you will need the following:

A computer running Linux, Windows, or macOS
Administrative privileges on your computer (if required for installation)
Internet access to download SFML

## Installing SFML on Linux

Open your terminal and type the following command to install SFML:

```bash
sudo apt-get install libsfml-dev
```

Wait for the installation process to complete.

Verify that SFML is installed by running the following command:

```bash
pkg-config --modversion sfml-all
```

This command should output the version number of the installed SFML library.

## Installing SFML on Windows

Go to the SFML downloads page and download the appropriate SFML version for your system.

Extract the downloaded archive to a location on your system.

Add the path to the "bin" directory of the extracted archive to your system's PATH environment variable.

Add the path to the "lib" directory of the extracted archive to your system's library search path.

Verify that SFML is installed by opening a command prompt and typing the following command:

```bash
sfml-config --version
```

This command should output the version number of the installed SFML library.

## Installing SFML on macOS

Open your terminal and install Homebrew by running the following command:

```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

Wait for the installation process to complete.

Install SFML by running the following command:

```bash
brew install sfml
```

Wait for the installation process to complete.

Verify that SFML is installed by running the following command:

```bash
pkg-config --modversion sfml-all
```

This command should output the version number of the installed SFML library.

And that's it! You should now have SFML installed on your Linux, Windows, or macOS system.
