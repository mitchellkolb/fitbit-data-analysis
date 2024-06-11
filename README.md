

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
    src="https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=Windows 10&logoColor=white"
    alt="Website Badge" />
</p>

This project is intended to showcase my knowledge when learning C and using file operations. The goal of this project was to dive into Fitbit data to analyze various health metrics like calories burned, distance walked, heart rate, and sleep quality. My main objectives were to grasp and apply data cleansing techniques, implement deduplication methods, and perform data analysis to compute meaningful results. Throughout this project, I covered topics such as C language programming, arrays, strings, pointers, structs, and basic string handling functions. I learned how to parse and convert strings from files, filter datasets, and understand the differences between array and pointer notation. Additionally, I created basic test cases, computed statistical summaries, and reported results in a structured format both on the screen and in a CSV file. This assignment reinforced the importance of accurate data handling, structuring programs effectively, and ensuring data integrity through cleaning and deduplication processes.


![fitbit-gif](resources/fitbit-gif.gif)


<details>
<summary style="color:#5087dd">Watch the Full Video Demo Here</summary>

[![Full Video Demo Here](https://img.youtube.com/vi/VidKEY/1.jpg)](https://www.youtube.com/watch?v=VidKEY)

</details>

---


# Table of Contents
- [What I Learned](#what-i-learned-in-this-project)
- [Tools Used](#tools-used-in-this-project)
- [Development Environment](#development-environment)
- [Team / Contributors / Teachers](#team--contributors--teachers)
- [How to Set Up](#how-to-set-up)
- [Project Overview](#project-overview)
- [Acknowledgments](#acknowledgments)

---

# What I Learned in this Project
- File operations like read/write from existing file to new files
- Programming conventions in C
- Data Organization/Mining techniques




# Tools Used in this Project
- C



# Development Environment
- VS Code
- Terminal
- Windows 10





# Team / Contributors / Teachers
- [Mitchell Kolb](https://github.com/mitchellkolb)
- Professor. Andy O'Fallon





# How to Set Up
This project was implemented on my local machine
- Clone this repository 
- Open terminal at the codebase `~.../fitbit-data-analysis/PA1/`
- Use this command to compile the codebase `gcc main.c equations.c`
- Run the code `./a.out`
- Check the Results.csv file to view the program output





# Project Overview
This project involves me using C to code a program that will analyze 24 hours of data form a .csv file of Fitbit data. Each record in the “FitbitData.csv” represents one minute of data and consists of eight fields. These include the following: 
1.    Patient ID 
2.    Minute 
3.    Calories 
4.    Distance (in miles) 
5.    Floors 
6.    Heartrate 
7.    Steps 
8.    Sleep level
I'm required to using structs and various strings to complete this task of categorizing all of the data points in the fitbit csv. I'm also going to have my project contain at least one header file (a .h file), two C source files (which 
must be .c files), and a local copy of the .csv file.
- I must parse each record into the corresponding fields, and store into the FitbitData array; note: not all fields have values, some are “empty” or null; if some of the fields are “empty” or null, then you must perform data cleansing and insert values to construct a record that is consistent with the others; the data inserted should not represent valid values.



## Project Details

### Introduction
In this project, we apply 


### Literature Review
In this we drew inspiration from various sources, including video tutorials online for 


### Technical Plan
The project employs a 


### Implementation Details

#### Files and Structure
- `game.py`: Contains the racing game environment and controls the car's movement.
> [!NOTE]
> These files were 


### Implementation
In this project

#### Results and Observations
During development,
<p float="left">
  <img src="resources/image1.png" alt="First Try" width="300" />
  <img src="resources/image2.png" alt="Final Try" width="307" />
</p>

#### Future Work
Future improvements could include



## References



--- 
# Acknowledgments
This codebase and all supporting materials was made as apart of a course for my undergrad at WSU for CPTS XXX - XXX in the Spring of 2022. 

---
