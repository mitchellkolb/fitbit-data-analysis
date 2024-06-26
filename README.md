
<h1 align="center">Fitbit Data Analysis</h1>

<p align="center">
  <img alt="Github top language" src="https://img.shields.io/github/languages/top/mitchellkolb/fitbit-data-analysis?color=0078D6">

  <img alt="Github language count" src="https://img.shields.io/github/languages/count/mitchellkolb/fitbit-data-analysis?color=0078D6">

  <img alt="Repository size" src="https://img.shields.io/github/repo-size/mitchellkolb/fitbit-data-analysis?color=0078D6">

  <img alt="Github stars" src="https://img.shields.io/github/stars/mitchellkolb/fitbit-data-analysis?color=0078D6" />
</p>

<p align="center">
<img
    src="https://img.shields.io/badge/Programming Language-%2300599b?style=for-the-badge&logo=C&logoColor=white"
    alt="Website Badge" />
<img
    src="https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=Windows&logoColor=white"
    alt="Website Badge" />
<img
    src="https://img.shields.io/badge/Clion-000000?style=for-the-badge&logo=Clion&logoColor=white"
    alt="Website Badge" />
</p>

This project is intended to showcase my skill set when I was first learning C in my CPTS 122 course. The goal was to read, clean, parse, and export some sample Fitbit data. This project is an overview of the topics and programming paradigms covered in the previous course (CPTS 121), where programming in C was introduced. Additionally, I've redone this assignment four years later after graduating to see how my programming skills have improved over my college career.

![fitbit-gif](resources/fitbit-gif.gif)

<details>
<summary style="color:#5087dd">Watch the Full Video Demo Here</summary>

[![Full Video Demo Here](https://img.youtube.com/vi/5XbRhzXmZzE/0.jpg)](https://www.youtube.com/watch?v=5XbRhzXmZzE)

</details>

---

# Table of Contents
- [What I Learned](#what-i-learned-in-this-project)
- [Tools Used / Development Environment](#tools-used--development-environment)
- [Team / Contributors / Teachers](#team--contributors--teachers)
- [How to Set Up](#how-to-set-up)
- [Project Overview](#project-overview)
  - [Files and Structure](#files-and-structure)
  - [Remaking the Project 4 Years Later](#remaking-the-project-4-years-later)
  - [Future Work](#future-work)
- [Acknowledgments](#acknowledgments)

---

# What I Learned in this Project
- Programming using predefined constraints and requirements.
- How to program effectively in C using structs, arrays, file I/O, pointers, and multiple files.
- How to use the CLion IDE and its debugger to diagnose issues.

# Tools Used / Development Environment
- C
- JetBrains CLion IDE
- CMake
- Windows 10

# Team / Contributors / Teachers
- [Mitchell Kolb](https://github.com/mitchellkolb)
- Professor Andy O'Fallon

# How to Set Up
This project was implemented on my local machine:
- Clone this repository.
- Open terminal at the codebase `~.../fitbit-data-analysis/Fitbit-2024/`.
- Install GCC to compile the codebase.
- Use this command: `gcc main.c equations.c`.
- Run the code: `./a.out`.
- Check the Terminal and Results.csv file to view the program output.

# Project Overview
This programming assignment focused on analyzing Fitbit data. The primary objective was to develop a program that could read and process some sample data generated by a Fitbit device, which is stored in a CSV file. The data included various data points such as steps taken, distance walked, heart rate, sleep quality, floors climbed, and calories burned. The assignment required implementing data cleansing techniques to handle missing or duplicate entries, parsing the data, and performing calculations to derive meaningful insights. These included total calories burned, total distance walked, total floors climbed, total steps taken, average heart rate, maximum steps taken in a minute, and the longest consecutive range of poor sleep.

Throughout this assignment, I was expected to apply several programming concepts in C, such as defining and using structures, handling arrays, strings, and pointers, parsing strings from files, and implementing basic data manipulation techniques. Additionally, I had to create and use enumerated types to represent sleep levels and ensure that the processed data was consistently formatted. The final output of the program was to be displayed on the screen and saved in a new CSV file, "Results.csv," with specific formatting requirements. The goal was to reinforce skills in data analysis, file handling, and C programming.

## Implementation Details

### Files and Structure
- `main.c`: Contains the main flow of the code.
- `equations.c`: Contains the functions that read data and export the struct data to the results.csv.
- `equations.h`: Contains the function prototypes and structs.

### Remaking the Project 4 Years Later
I completed this assignment during the summer of 2020, and I chose to start a new codebase in 2024 and solve it again to see how much I've improved over the years. Two things I was keeping track of when remaking this project were how long it took me to finish it and if my code was better organized than when I first completed it. Here are the improvements from both attempts:
- 2020
  - Time taken: 7 days
  - Code quality: Subpar, and some features were missing when I finished it.
- 2024
  - Time taken: ~9 hours
  - Code quality: Feature complete and the code is better organized.

### Future Work
This project's requirements are complete, but one thing I could work on in the future would be to complete it again in 2028 to see how much I've improved since my last 2024 rendition.

---
# Acknowledgments
This codebase and all supporting materials were made as part of a course for my undergrad at WSU for CPTS 122 - Data Structures and Algorithms in the Summer of 2020 and then reworked in the Summer of 2024.

---
