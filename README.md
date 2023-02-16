*CMAKE-TUTORIAL-WORKSOUP*
# Writing Your First CMake and Compiling a C++ Project with SFML

In this tutorial, we will walk through the process of installing CMake, creating a CMake file to compile a single file, and creating a CMake file to compile an entire project that use dependencies.

## CMake summary

CMake is a powerful and popular tool used to build software projects across various platforms. Its popularity stems from the fact that it allows developers to generate platform-specific build files from a single source configuration, making it an efficient and time-saving alternative to manually writing build files for each platform.

<details>
<summary>More ...</summary>
CMake's power lies in its flexibility and ability to handle complex build systems. It supports multiple programming languages and offers a wide range of features, including the ability to link external libraries and manage dependencies.

CMake is particularly useful for large software projects, where managing dependencies and building for multiple platforms can be challenging. With CMake, developers can define the build process once and generate platform-specific build files for Windows, macOS, Linux, and more.

In summary, CMake is a useful tool for managing and automating the build process, and it's particularly powerful when working on large, complex projects or building for multiple platforms. It can save time and reduce the risk of errors when managing dependencies and linking external libraries, making it a popular choice among developers.
</details>

##

By the end of this tutorial, you will have a basic understanding of how to use CMake to build and compile C/C++ projects, and how to link and build a library to your project.

**If we see ANYONE using ChatGPT, or copilot because you do not want to think a little bit, we will tell your parents that your are a very bad programmer** and you will be put absent to this workshop.

<details>
<summary>Do not forget to ask us when you are stuck.</summary>
We are here to help you. Even if most of the time most of your responses will be "Google it" because you don't want to think a little bit. (We know, workshop can be boring but trust us, it will be worth it in the end because you will use CMake a lot during your Epitech journey.)
</details>

## Prerequisites

Before we begin, you will need the following:

- CMake installed on your system.
- The SFML (not CSFML) library installed on your system.
- A C/C++ compiler installed on your system.
- Knowing how to read documentation. (you will need it a lot in this tutorial, but do not worry, the CMake documentation is very ~~bad~~ well written :) .)

**You can refer to the next sections of this README for instructions on how to install CMake and the SFML library on your system.**

## Installation (15 min max)

To learn more about how to **install CMake** on Linux, Windows or MacOS, check out the [installation guide](installDoc/InstallCmake.md).

To learn more about how to **install the SFML** library on Linux, Windows or MacOS, check out the [installation guide](installDoc/InstallSFML.md).

## Introduction (15 min max)

### Project1 - Creating a CMake project for a single file

#### Notions you will learn :

- CMakeLists.txt
- cmake_minimum_required()
- project()
- set()
- add_executable()

First, let's create a CMake file to compile a single C/C++ file. In this example, we will create a CMake file to compile a "hello world" program.

Navigate to the Project1 directory and create a "CMakeLists.txt" file.

> The name of the CMake file must be "CMakeLists.txt", else it will not be recognized by CMake.

In the CMake file, **set the minimum version of CMake** required to build the project using the [`cmake_minimum_required()`](https://cmake.org/cmake/help/latest/command/cmake_minimum_required.html) command. We will set the minimum version to 3.20.

<details>
<summary>Click here for more detail about why we set the minimum version to 3.20</summary>
We need to set the minimum version of CMake in our project because different versions of CMake may have different features and syntax. If we use a feature or syntax that is not supported by a version of CMake that is lower than the minimum version we have set, CMake will fail to generate the necessary build files for our project.

By setting the minimum version of CMake in our project, we can ensure that the features and syntax we use are supported by all versions of CMake that are equal to or greater than the minimum version. This makes our project more portable and easier to build across different systems.
</details>

Then we will create a project using the [`project()`](https://cmake.org/cmake/help/latest/command/project.html) command. We will name the project "HelloWorldProject" (or anything you want).

Next, we will create a variable called "SRCS" (for our sources) and set it to the name of the source file we want to compile.

To create a variable in CMake, we use the [`set()`](https://cmake.org/cmake/help/latest/command/set.html) command. The first argument is the name of the variable, and the second argument is the value of the variable, here it will be "SimpleHelloWorldProgram.cpp".

> When your file is in a different directory, you can specify the path to the file in the value of the variable. For example, if your file is in the "src" directory, you can set the value of the variable to "src/SimpleHelloWorldProgram.cpp".

Finally, we will use the [`add_executable()`](https://cmake.org/cmake/help/latest/command/add_executable.html) command to create an executable from the source file. To name the executable, we will use the [`PROJECT_NAME`](https://cmake.org/cmake/help/latest/variable/PROJECT_NAME.html) variable. This variable is automatically created by CMake and contains the name of the project. This variable as been set when you called the [`project()`](https://cmake.org/cmake/help/latest/command/project.html) function. Also, we will use the `SRCS` variable to specify the source file we want to compile.

> To use a variable in CMake, we use the `${}` syntax.

Now that we have created a CMake file to compile a single file, let's compile it.

But first, create a build directory in the Project1 directory and navigate to it.

Then run the following command to configure the project:

```bash
cmake ..
```

This will configure the project. What this means is that CMake will create a Makefile in the build directory that will be used to compile the project.

<details>
<summary>Click here for "Why .. ?"</summary>
In the command cmake .., the .. specifies the parent directory of the current directory.

When we navigate into the build directory in our terminal or command prompt, we are changing our working directory to the build directory. The .. tells CMake to look in the parent directory of the build directory for the CMakeLists.txt file.

Since our CMakeLists.txt file is in the parent directory, specifying .. allows CMake to find the file and generate the necessary build files.

In summary, cmake .. is a command that tells CMake to generate the build files for our project using the CMakeLists.txt file in the parent directory of our current working directory.
</details>

Then to compile the project, run the following command:

```bash
cmake --build .
```

This will compile the SimpleHelloWorldProgram.cpp file and create an executable named by the name of the project in the build directory.

But, if you want to compile the project in a different directory, you can specify the path to the directory you want to compile the project in.

The [`CMAKE_RUNTIME_OUTPUT_DIRECTORY`](https://cmake.org/cmake/help/latest/variable/CMAKE_RUNTIME_OUTPUT_DIRECTORY.html) variable is used to specify the path to the directory where the executable will be created.

CMake automatically creates this variable when you call the [`project()`](https://cmake.org/cmake/help/latest/command/project.html) function. This variable contains the path to the directory where the executable will be created.

So you can reset the value of this variable to the path to the directory where you want to compile the project.

You can use the [`CMAKE_SOURCE_DIR`](https://cmake.org/cmake/help/latest/variable/CMAKE_SOURCE_DIR.html) variable to get the path to the directory where the CMakeLists.txt file is located.

> Do not for get to use the `${}` syntax to use a variable in CMake.

Now reconfigure then compile the project...

And tada! You have created your first CMake project, and the binary is in the root directory.

Try to execute it now!

## Advanced (35 min max)

In this section you will learn to use CMake in a more advanced way. You will learn how to use CMake to use a library (how to link it) and how to build a library.

### Project2 - Linking a library (10 min max)

The library you will link to your project is the SFML library.

SFML (as your probably know) is a library that allows you to create games and graphical applications.

You will learn how to use the `target_link_libraries` command, and how to use the `find_package` command to link the SFML library to your project.

#### Downloading a library (10 min max)

With CMake, you can download a library from the internet and link it to your project. It is the main principle of CM

In this section, we will download the SFML library from the internet and link it to our project.

### Project3 - Building a library (20 min max)

You will learn how to build SFML and how to use it in your own project.

### Project4 - Creating a CMake project for an entire project

In this section, we will create a CMake file to compile an entire project.

### Final Project - Creating a CMake project for your own tek or personnal project.

Now you know how to use CMake to compile a project, you can use it to compile your own project. Take any project and have fun. Kidding, CMake is not fun.
