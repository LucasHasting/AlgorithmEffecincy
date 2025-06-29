# Count Sort Analysis
Project was created in my CS 355 (Data Structures and Algorithms) class. The project was to provide an analysis of the count sort algorithm including its time complexity and a visualization of the speed of the algorithm. The results of this analysis can be found in [Algorithm Efficiency.pptx](). The project was done with the help of Ethan Nix and Krutivas Pradhan.  

## Table of Contents
- [Project-Installation](#project-installation)
- [C++-Program](#c++-program)
- [R-Script](#r-script)
- [Project-Overview](#project-overview)

## Project-Installation

R and C++ are both needed for this project, see instructions below for both of those.

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

# C++-Program

## Table of Contents
- [C++-Installation](#c++-installation)
- [Compile-the-program](#compile-the-program)
- [Execute-the-program](#execute-the-program)
- [Program-Usage](#program-usage)
- [Program-Example](#program-example)

## C++-Installation

The programs in this repository can be executed using the C++ language and the g++ compiler.

g++ for [Windows](https://sourceforge.net/projects/mingw/), don't forget to add the binary to the [path environment variable](https://www.architectryan.com/2018/03/17/add-to-the-path-on-windows-10/).

g++ can be installed on Linux using your favorite package manager.

## Compile-the-program

### Option 1: using [Make](https://www.gnu.org/software/make/)
Run the following:
```sh
make all
```

### Option 2: without Make
Run the following:
```sh
g++ analysis_functions.cpp countSort.cpp testProject.cpp -o count_sort
```

## Execute-the-program

### Windows
```sh
count_sort.exe
```

### Linux/Mac
```sh
./count_sort.out
```

## Program-Usage
The program runs a stress test on the Count Sort algorithm and records the results in the [data.csv]() file. It uses "." to indicate a pass through a loop, or in other words, to indicate the programs progress. The program then indicates it is finished by displaying the word "done". The program can take several minutes to execute completely and it is recommended to not do anything else on the computer the program is running on until it is finished for best results.

## Program-Example

![EXAMPLE](examples/example1-1.png)
![EXAMPLE](examples/example1.png)

# R-Script

## Table of Contents

- [R-Installation](#r-installation)
- [Script-Usage](#script-usage)
- [Script-Example](#script-example)

## R-Installation

You need [R](https://rstudio-education.github.io/hopr/starting.html) for this project, [RStudio](https://rstudio-education.github.io/hopr/starting.html) is recommended.

#### Run from the command line
1. go to the command line and run the following:
   ```sh
   Rscript Analyze.R
   ```
2. All graphs are located in the project folder in the Rplots.pdf file

#### Run from RStudio
1. Click File (located at the top left) -> Open File
2. Open Analyze.R
3. Click Session (located near File) -> Set Working Directory -> To Source File Location
4. Click where the script is
5. Click ctrl (cmd on mac) + a
6. Click the run button (located at the top below the tabs)
7. The graphs are located at the bottom right, the left and right arrows can be used to select a graph

## Script-Usage

The main purpose of the R script is to subset the data in the [data.csv](https://github.com/LucasHasting/Applied-Statistics-Project/blob/main/Discrimination%20in%20the%20California%20Department%20of%20Defense.pdf) file and to generate graphs based on the subsetted data, the graphs can be found in the [Graphs](https://github.com/LucasHasting/Applied-Statistics-Project/blob/main/Discrimination%20in%20the%20California%20Department%20of%20Defense.pdf) directory.

## Script-Example

### CMD

![EXAMPLE](examples/example1-2.png)
![EXAMPLE](examples/example2.png)
![EXAMPLE](examples/example3.png)

### RStudio

![EXAMPLE](examples/example4.png)

# Project-Overview

[countSort.cpp](): contains the count sort algorithm.  
[testProject.cpp](): stress tests count sort and records the data in a csv file.  
[Analyze.R](): generates graphs of the data which can be found in the [Graphs]() directory.
