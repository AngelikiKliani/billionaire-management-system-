# billionaire-management-system-
A C program implementing a doubly circular linked list to manage billionaire records with automatic bill code generation and file persistence.

README
Billionaire Management System
A C program that implements a doubly circular linked list to manage billionaire records with automatic bill code generation and file persistence.

Authors
Aggeliki Kliani (AM: 2022202300205, dit23205@go.uop.gr)

Christianna Tsouko (AM: 2022202300014, dit23014@go.uop.gr)

Features
Create new billionaire records with name, location, source of income, birth country, gender, birth date/time, and net worth

Automatic bill code generation (11-digit validation code using Luhn algorithm)

Doubly circular linked list implementation for efficient traversal

File operations - Save to and load from text files

Delete operations - Remove newest or oldest entries

Sum calculation - Total wealth of all billionaires

Data Structure
The program uses a custom billionaire structure:

name[50] - Full name

location[50] - Current residence

source[100] - Source of income

birthcountry[50] - Country of birth

gender[10] - Gender

birthdate - Date of birth (day/month/year)

birthtime - Time of birth (hour:minutes)

money - Net worth in billions (double)

billCode - Pointer to dynamically allocated 11-digit validation code

next/prev - Pointers for doubly circular linked list

Commands
Command	Format	Description
newbil	newbil Name Surname;City/Country;Source;Birth Country;Gender;DD/MM/YYYY HH:MM;Billions;	Create new billionaire entry
sum	sum	Display total wealth of all billionaires
deleteN	deleteN	Remove the most recently added billionaire
deleteO	deleteO	Remove the oldest billionaire
save	save filename.txt	Save all records to file
load	load N filename.txt	Load N billionaires from file
exit	exit	Exit program (frees memory)
Input Format Example
text
newbil Elon Musk;USA;Tesla/SpaceX;South Africa;Male;28/06/1971 12:15;245.6;
Bill Code Generation
The system automatically generates an 11-digit validation code for each billionaire using a modified Luhn algorithm:

First 10 digits: Random numbers with odd-position digits doubled

11th digit: Checksum calculated from the sum of first 10 digits

File Format
Data is stored in plain text format using semicolons as delimiters:

text
Name;Location;Source;BirthCountry;Gender;DD/MM/YYYY;HH:MM;Money
Compilation
bash
gcc -o billionaire_manager KlianiTsouko.c
Usage
bash
./billionaire_manager
Memory Management
Dynamic allocation for bill codes and file names

Complete memory cleanup on program exit

Circular linked list properly maintained on all operations

Notes
Fields can be left unknown by typing "?" or "Unknown"

The list maintains insertion order (newest at the end)

All operations preserve the circular nature of the list

The program includes input validation for commands
