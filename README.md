*CMAKE-TUTORIAL-WORKSOUP*
# Writing Your First CMake and Compiling a C++ Project with SFML

In this tutorial, we will walk through the process of **installing CMake**, creating a CMake file to **compile a single file**, and then, creating a CMake file to **compile an entire project that use dependencies**.

## CMake summary

CMake is a powerful and popular tool used to **build software** projects across **various platforms**. Its popularity stems from the fact that it allows developers to **generate platform-specific build** files from a single source configuration, making it an efficient and time-saving alternative to manually writing build files for each platform.

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
We are here to help you. Even if most of the time most of our responses will be "Google it" because you did not want to think a little bit. (We know, workshop can be boring but trust us, it will be worth it in the end because you will use CMake a lot during your Epitech journey.)
</details>

## Prerequisites

Before we begin, you will need the following:

- [CMake](https://cmake.org/) installed on your system.
- The [SFML](https://www.sfml-dev.org/index-fr.php) (not CSFML) library installed on your system.
- A C/C++ compiler installed on your system.
- Knowing how to read documentation. (you will need it a lot in this tutorial, but do not worry, the CMake documentation is very ~~bad~~ well written :) .)

**You can refer to the next sections of this README for instructions on how to install CMake and the SFML library on your system.**

## Installation (15 min max)

To learn more about how to **install CMake** on Linux, Windows or MacOS, check out the [installation guide](installDoc/InstallCmake.md).

To learn more about how to **install the SFML** library on Linux, Windows or MacOS, check out the [installation guide](installDoc/InstallSFML.md).

## Introduction (25 min max)

### Project1 - Creating a CMake project for a single file

#### Fonctionnalities you will learn :

- CMakeLists.txt
- cmake_minimum_required()
- project()
- set()
- add_executable()
- target_include_directories()

First, let's create a CMake file to compile a single C/C++ file. In this example, we will create a CMake file to compile a "hello world" program.

Navigate to the Project1 directory and create a "CMakeLists.txt" file.

> The name of the CMake file must be "CMakeLists.txt", else it will not be recognized by CMake.

In the CMake file, **set the minimum version of CMake** required to build the project using the [`cmake_minimum_required()`](https://cmake.org/cmake/help/latest/command/cmake_minimum_required.html) command. We will set the minimum version to 3.20.

> Every command used in this wkorshop is a hyperlink to his documentation.

<details>
<summary>Click here for more detail about why we set the minimum version to 3.20</summary>
We need to set the minimum version of CMake in our project because different versions of CMake may have different features and syntax. If we use a feature or syntax that is not supported by a version of CMake that is lower than the minimum version we have set, CMake will fail to generate the necessary build files for our project.

By setting the minimum version of CMake in our project, we can ensure that the features and syntax we use are supported by all versions of CMake that are equal to or greater than the minimum version. This makes our project more portable and easier to build across different systems.
</details>

Then we will create a project using the [`project()`](https://cmake.org/cmake/help/latest/command/project.html) command. We will name the project "HelloWorldProject" (or anything you want).

Set the C++ standard to C++17 using the [`set()`](https://cmake.org/cmake/help/latest/command/set.html) command.

The variable [`CMAKE_CXX_STANDARD`](https://cmake.org/cmake/help/latest/variable/CMAKE_CXX_STANDARD.html) is a CMake variable that specifies the C++ standard to use when compiling the project. We will set it to 17, which is the C++17 standard.

> It also work with C standard, but you should use CMAKE_C_STANDARD.

To create / redefine a variable in CMake, we use the [`set()`](https://cmake.org/cmake/help/latest/command/set.html) command. The first argument is the name of the variable, and the second argument is the value of the variable or the list of values of the variable.

Next, we will create a variable called `SRCS` (for our sources) and set it to the name of the source file we want to compile. We will also create a variable called `INCLUDES` (for our includes) and set it to the name of the directory where our header files are located.

> When your file is in a different directory, you can specify the path to the file in the value of the variable. For example, if your file is in the "srcs" directory, you can set the value of the variable to "srcs/SimpleHelloWorldProgram.cpp".

We are almost at the end, we will use the [`add_executable()`](https://cmake.org/cmake/help/latest/command/add_executable.html) command to create an executable from the source file. To name the executable, we will use the [`PROJECT_NAME`](https://cmake.org/cmake/help/latest/variable/PROJECT_NAME.html) variable. This variable is automatically created by CMake and contains the name of the project. This variable as been set when you called the [`project()`](https://cmake.org/cmake/help/latest/command/project.html) command. Also, we will use the `SRCS` variable to specify the source file we want to compile.

> To use a variable in CMake, we use the `${}` syntax.

Finally, we will use the [`target_include_directories()`](https://cmake.org/cmake/help/latest/command/target_include_directories.html) command to specify the directories where our header files are located. We will use the `INCLUDES` variable to specify the directory where our header files are located and the `PUBLIC` keyword to specify that the directory is public.

> You will specify your target in the first argument. Your "target" is the executable you want to create, so its name of your project. And then you will specify the directories where your header files are located in the second argument, so your INCLUDE variable.

<details><summary>More precision with PUBLIC, PRIVATE, and INTERFACE keywords.</summary>
In CMake, PUBLIC, PRIVATE, and INTERFACE are keywords used to specify the visibility of properties and targets.

PUBLIC means that a property or target is part of the public API of a library or executable target, and should be available to other targets that depend on the current target. This means that if another target depends on the current target, it will also have access to the public properties or targets included with PUBLIC.

PRIVATE, on the other hand, means that a property or target is used only within the current target itself, and should not be visible to other targets that depend on the current target. This means that if another target depends on the current target, it will not have access to the private properties or targets included with PRIVATE.

In summary, PUBLIC, PRIVATE, and INTERFACE are used to specify the visibility of properties and targets in CMake, with PUBLIC indicating that a property or target is part of the public API, PRIVATE indicating that it is used only within the current target, and INTERFACE indicating that it should be visible to other targets that depend on the current target, but should not be used within the current target itself.
</details>

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

But, you will probably say : "HO MY GOD WHERE IS MY EXECUTABLE HO MY GOD WHAT  DID I DO AAAAAAAAAAAAH???". Stop panicking pal, it's normal.
CMake doesn't create the executable in the build directory, it creates it in the directory where the CMakeLists.txt file is located.

If you want to compile the project in a different directory, you can specify the path to the directory you want to compile the project in.

The [`CMAKE_RUNTIME_OUTPUT_DIRECTORY`](https://cmake.org/cmake/help/latest/variable/CMAKE_RUNTIME_OUTPUT_DIRECTORY.html) variable is used to specify the path to the directory where the executable will be created.

CMake automatically creates this variable when you call the [`project()`](https://cmake.org/cmake/help/latest/command/project.html) command. This variable contains the path to the directory where the executable will be created.

So you can reset the value of this variable to the path to the directory where you want to compile the project.

> Set the runtime directorie before the [`add_executable()`](https://cmake.org/cmake/help/latest/command/add_executable.html) command.

You can use the [`CMAKE_SOURCE_DIR`](https://cmake.org/cmake/help/latest/variable/CMAKE_SOURCE_DIR.html) variable to get the path to the directory where the CMakeLists.txt root file is located.

<details><summary>Root ? What do you mean by root ?</summary>
When I say root file, I mean the CMakeLists.txt file that is located in the root directory of your project, it is the first file that CMake will read when you configure your project.
</details>

> Do not forget to use the `${}` syntax to use a variable in CMake.

Now reconfigure then compile the project...

And tada! You have created your first CMake project, and the binary is in the root directory.

Try to execute it now!

## Advanced (45 min max)

In this section you will learn to use CMake in a more advanced way. You will learn how to use CMake to link any library (like SFML) and how to build a custom library.

### Project2 - Linking a library (30 min max)

#### Fonctionnalities you will learn :

- target_link_libraries()
- find_package()
- include()
- FetchContent_Declare()
- FetchContent_MakeAvailable()

The library you will link to your project is the SFML library.

SFML (as your probably know) is a c++ library that allows you to create games and graphical applications.

You will learn how to use the [`find_package`](https://cmake.org/cmake/help/latest/command/find_package.html) command, and how to use the [`target_link_libraries`](https://cmake.org/cmake/help/latest/command/target_link_libraries.html) command to find and link the SFML library to your project.

First, like in the previous section, navigate into the Project2 directory and create a CMakeLists.txt file, then :

- Set the minimum version of CMake to 3.20.
- Then create a project named "SFMLProject" or else.
- Set the C++ standard to C++17.
- Set the `SRCS` and `INCLUDE` variables.
- Then create an executable from the source file.
- Link the `INCLUDE` variable to the executable.

> You should know how to do this by now. If your lost, ask for help.

If you try to compile the project, you will get an error because the SFML library is not linked to the project.

To do so you will first use the [`find_package`](https://cmake.org/cmake/help/latest/command/find_package.html) command to find the SFML library. It will search for the library in the system and set the variables that are used to link the library to the project.

We will use the [`REQUIRED`](https://cmake.org/cmake/help/latest/command/find_package.html#required) option to make the [`find_package`](https://cmake.org/cmake/help/latest/command/find_package.html) command *fail* if the library is *not found*.

You can do a **google search** to find the name of the package SFML you need to use in the [`find_package`](https://cmake.org/cmake/help/latest/command/find_package.html) command.

Then you will use the [`target_link_libraries`](https://cmake.org/cmake/help/latest/command/target_link_libraries.html) command to link the SFML library to the project. Like all "target_..." commands, it takes the target as the first argument.

> Use it after the [`add_executable`](https://cmake.org/cmake/help/latest/command/add_executable.html) command, because if you want to specify a target (the first argument), the target must be created before, with the [`add_executable`](https://cmake.org/cmake/help/latest/command/add_executable.html) command or the [`add_library`](https://cmake.org/cmake/help/latest/command/add_library.html) command.

And finally, use the [`target_include_directories`](https://cmake.org/cmake/help/latest/command/target_include_directories.html) command to include the SFML library header files to the project.

> When a package is found with the [`find_package`](https://cmake.org/cmake/help/latest/command/find_package.html) command, CMake automatically creates a variable that contains the path to the directory where the header files are located. The name of this variable is the name of the package in uppercase, with the `_INCLUDE_DIR` suffix.

Now reconfigure then compile the project...

And tada! You have linked the SFML library to your project.

Try to execute it now!

#### Downloading a library

With CMake, you can **download a library** from the internet and link it to your project. It is the main principle of CMake, **managing dependencies**.

In this section, we will **download the SFML library** from the internet using CMake and link it to our project.

Include the [`FetchContent`](https://cmake.org/cmake/help/latest/module/FetchContent.html) module with the [`include`](https://cmake.org/cmake/help/latest/command/include.html) command.

> The include command is used to include a CMake file and so use the commands declared in it. (yes you can make your own commands with CMake)

Use the [`FetchContent_Declare`](https://cmake.org/cmake/help/latest/module/FetchContent.html#command:fetchcontent_declare) command to download the SFML library from the internet.

> You can use the git repository of the SFML library to download it.

Then use the [`FetchContent_MakeAvailable`](https://cmake.org/cmake/help/latest/module/FetchContent.html#command:fetchcontent_makeavailable) command to make the library available to the project.

> Because you are very intelligent, you did not put [`FetchContent_Declare`](https://cmake.org/cmake/help/latest/module/FetchContent.html#command:fetchcontent_declare) **AFTER** the [`target_link_libraries`](https://cmake.org/cmake/help/latest/command/target_link_libraries.html). Yes?

Use the [`target_link_libraries`](https://cmake.org/cmake/help/latest/command/target_link_libraries.html) command to link the SFML library to the project.

And finally, use the [`target_include_directories`](https://cmake.org/cmake/help/latest/command/target_include_directories.html) command to include the SFML library header files to the project.

### Project3 - Building a library (10 min max)

In this section, you will learn how to build a custom library with CMake.

#### Fonctionnalities you will learn :

- add_library()

Like the first section, navigate into the Project3 directory and create a CMakeLists.txt file, do the exact same thing as in the first section, but instead of creating an executable, create a library.

Do everything you did in the second section, but instead of creating an executable, create a library.

You will not need to link the SFML.

> Libraries can be linked to other libraries too, using the same command as for executables.

Use the [`add_library`](https://cmake.org/cmake/help/latest/command/add_library.html) command to create a library.

Its behavior is the same as the [`add_executable`](https://cmake.org/cmake/help/latest/command/add_executable.html) command, but it creates a library instead of an executable.

> To link a custom library to a project, you will use the [`target_link_libraries`](https://cmake.org/cmake/help/latest/command/target_link_libraries.html) command to a target (executable or library).

**Configure and compile the project**, you should have a library created in the build directory.

If you want to change the output directory of the library you can use the [CMAKE_ARCHIVE_OUTPUT_DIRECTORY](https://cmake.org/cmake/help/latest/variable/CMAKE_ARCHIVE_OUTPUT_DIRECTORY.html) variable. But it is **not necessary**.

### Project4 - Creating a CMake project for an entire project (25 min max)

#### Fonctionnalities you will learn :

- add_subdirectory()

In this section, we will create a CMake file to **compile an entire project**.

There is a a new directory called `lib` in the root directory of the project, it contains the library you will build and link.

Create a CMakeLists.txt file in the root directory of the project AND in the `lib` directory.

Why in the `lib` directory ? Because its preferable to separate the CMake files of the project and the CMake files of the library.

So you will do the same as before, but you will create a library in the `lib` directory and link it to the project.

To access the `lib` directory, you will use the [`add_subdirectory`](https://cmake.org/cmake/help/latest/command/add_subdirectory.html) command inside the root CMakeLists.txt file.

## Final Project - Creating a CMake project for your own tek or personnal project. (no time limit)

When arriving at this point, come see us, we will check your work to see if anything is missing.

Now you know how to use CMake to compile a project, you can use it to compile your own project. Take any project and have fun. Kidding, CMake is not fun, only usefull.
