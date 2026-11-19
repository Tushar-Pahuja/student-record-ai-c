# AI-Assisted Student Record and Result Management System

## Project Overview

This project is a console-based Student Record and Result Management System developed using the C programming language.

The program allows users to manage student records, calculate academic performance, and provide simple CGPA-based academic advice.

## Features

- Add student details
- Search student by SAP ID
- Display all student records
- Calculate CGPA using available SGPA values
- Calculate average CGPA of students belonging to each year
- Delete a student record
- Sort student records by SAP ID
- Sort student records by Name
- AI-Assisted Academic Advisor
- Menu-driven interface

## Student Information Stored

The program stores the following details:

- SAP ID
- Roll Number
- Name
- Phone Number
- Email ID
- Year
- Current Semester
- SGPA for available semesters

## AI-Assisted Academic Advisor

The Academic Advisor provides recommendations according to the student's CGPA.

- CGPA 9.0 or above: Excellent Performance
- CGPA 7.5 to 8.99: Good Performance
- CGPA 6.0 to 7.49: Needs Improvement
- CGPA below 6.0: Requires Immediate Attention

The suggestions for designing these categories were obtained with the help of ChatGPT and were implemented in C using if-else statements.

## Technologies Used

- C Programming Language
- GitHub
- ChatGPT as an AI learning assistant

## How to Run

1. Download or clone this repository.
2. Compile the C source file using a C compiler.
3. Run the compiled program.
4. Select the required operation from the menu.

Example using GCC:

gcc 590032177.c -o student

Run:

./student

## Project File

Main source code:

590032177.c

## Author

Tushar Pahuja  
SAP ID: 590032177

## Course

Programming in C  
B.Tech CSE - Semester I  
UPES
