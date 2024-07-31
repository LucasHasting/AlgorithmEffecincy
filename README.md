# Count Sort Analysis
Project was created in my Data Structures and Algorithms class.  
Project was done with the help of Ethan Nix and Krutivas Pradhan.  

## Table of Contents
- [C++-Program](#installation)
- [R-Script](#compile-the-program)

# C++ Programs

## Table of Contents
- [Installation](#installation)
- [Compile-the-program](#compile-the-program)
- [Execute-the-program](#execute-the-program)
- [Usage](#usage)
- [Example](#example)
- [Program-Overview](#program-overview)

## Installation

You need the [C++](https://sourceforge.net/projects/mingw/) language installed on your system, the program can be executed using the g++ compiler.

### Option 1: using [git](https://git-scm.com/downloads)
1. Clone the repository:

    ```sh
    git clone https://github.com/LucasHasting/AlgorithmEffecincy.git
    ```

2. Navigate to the project directory:

    ```sh
    cd AlgorithmEffecincy
    ```
    
### Option 2: without git
1. Download the project as a zip file
2. [Extract the zip file](https://www.wikihow.com/Unzip-a-File)
3. Find the location of the files
4. Copy the path
5. go to the command line and run the following:
   ```sh
   cd /path/to/files
   ```

## Compile the program

### Option 1: using [Make](https://www.gnu.org/software/make/)
Run the following:
```sh
make all
```

### Option 2: without Make
Run the following:
```sh
g++ maps.cpp driver.cpp -o count_sort
```

## Execute the program

### Windows
```sh
count_sort.exe
```

### Linux/Mac
```sh
./count_sort.out
```

## Usage
The program is a command line, menu based, user interface. By entering the number associated with an option it will perform a certain operation. The program has multiple menus, the first being the main menu where you can sign in, create an account, or exit the program. When creating an account it asks for the username and password, and the password is hidden using *. Upon successfull login you have the option to change the accounts username and password, along with deleteing the account, or you can choose to sign out.

## Example

![EXAMPLE](examples/example1.png)  
![EXAMPLE](examples/example2.png)  

## Program-Overview
countSort.cpp contains the count sort algorithm.  
testProject.cpp stress tests count sort and records the data in a csv file.  
Two csv files are used due to a previous error.  
Analyze.R generates graphs of the data which can be found in the Graphs directory.

# R-Script
