# WL_F00k3r — Windows License Fooker (KMS Activation Tool)

             $$$$$$
            $$    $$
            $$$  $$$
            $$ $$ $$
            $$    $$
            $$    $$
            $$    $$
            $$    $$$$$$$
      $$$$$$$$    $$    $$
     $$$$$   $$    $$    $$$$$$
    $$$ $$   $$    $$    $$   $$
    $$  $$   $$    $$    $$   $$
    $$  $$   $$    $$    $$   $$
    $$  $$   $$    $$   $$$   $$
    $$  $$   $$    $$    $    $$
    $$    $$$  $$$$  $$$$   $ $$
    $$                        $$
     $$                       $$
      $$$                     $$
       $$$$                 $$$
         $$                 $
         $$$               $$

         FUCK YOU BILL GATES
       
A lightweight Windows activation utility that leverages the KMS (Key Management Service) method to activate supported Windows versions seamlessly and efficiently.




## Table of Contents:

- [**Introduction**](#introduction)
- [**Technologies Used**](#technologies-used)
- [**Features**](#features)
- [**Requirements**](#requirements)
- [**How to Use/Installation**](#how-to-useinstallation)
- [**How It Works**](#how-it-works)
- [**Contributing**](#contributing)
- [**License**](#license)

## Introduction

WL_F00ker is a simple yet effective software solution designed to automate the Windows activation process via KMS (Key Management Service). No more hassle with manual keys or activation errors — just run, activate, and go!


## Features
Activates Windows operating systems via KMS emulation.

Supports Windows 7, 8, 8.1, 10, and Server editions.

Clean and minimal CLI interface.

Lightweight and fast.

Logs activation status and attempts for user review.

Can be integrated into scripts for automated deployments.



## Technologies Used: 

🖥️ C/C++

🧠 Object-Oriented Programming (P.O.O.)

💾 Binary Database

⚙️ Windows API


#### Requirements:
Before running WL_Fooker, ensure your system meets the following requirements:

-   Windows 7 / 8 / 8.1 / 10 / Server editions.

-   Admin privileges (required for activation routines).

-   Internet connection (optional, for genuine KMS server mode).

## Development requirements:

-   GNU/GCC Compiler (if compiling from source).

-   Windows SDK (for Windows-specific builds).

-   A text editor or IDE (e.g., Visual Studio Code, Eclipse CDT).


Supported Operating Systems:


## How to Use/Installation:

Supported Operating Systems:

 | S.O.  | Version |
 | ----- | --- |
 | Windows  | [**7,8,vista,10**](#windows)  |



-   ## Windows
Basically Download the zip file, or clone the repository via the git bash promt.
1) Clone the repository:

bash
```bash
#!/bin/bash
git clone https://github.com/username/WL_Fooker.git
cd WL_Fooker

```
2) Compile the Program:

bash
```bash
g++ WL_Fooker.cpp -o WL_Fooker.exe
```

3) Run the Program:

-   Execute the .exe file from the "bin" folder (after compiling it from the source code, of course...) or just run it from the command prompt.
```bash
cd bin
./WL_Fooker.exe
```


## How It Works
WL_F00ker emulates the behavior of an internal Key Management Service server, generating valid responses to Windows activation requests. The tool communicates with the Windows Software Protection Platform via the slmgr utility or native API calls, tricking the system into accepting the activation as genuine. This enables seamless unlocking of Windows features without requiring a retail product key.

## Note
 - This tool is intended for educational purposes and system administrators testing deployment setups.

- Misuse of this software may violate the Microsoft EULA.

- Always ensure compliance with licensing policies when using any activation tool.

## Contributing

If you'd like to contribute to the project, feel free to fork the repository, make your changes, and submit a pull request. Any improvements or suggestions are highly appreciated.

-   Fork the project.
-   Create a new branch.
-   Make your changes and commit them.
-   Submit a pull request.



