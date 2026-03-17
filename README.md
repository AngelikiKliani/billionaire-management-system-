# billionaire-management-system-
A C program implementing a doubly circular linked list to manage billionaire records with automatic bill code generation and file persistence.

**Table of Contents**
Features
Data Structure
Commands
Getting Started
Usage Examples
Bill Code Generation
File Format
Compilation


**Features**
Create new billionaire records with name, location, source of income, birth country, gender, birth date/time, and net worth

Automatic bill code generation - 11-digit validation code using Luhn algorithm

Doubly circular linked list implementation for efficient traversal in both directions

File operations - Save to and load from text files

Delete operations - Remove newest or oldest entries

Sum calculation - Total wealth of all billionaires

Dynamic memory management - Proper allocation and deallocation

**Data Structure**
typedef struct {
    int year;
    int month;
    int day;
} mydate;

typedef struct {
    int hour;
    int minutes;
} mytime;

typedef struct bilList {
    char name[50];              // Full name
    char location[50];           // Current residence
    char source[100];            // Source of income
    char birthcountry[50];       // Country of birth
    char gender[10];             // Gender
    mydate birthdate;            // Date of birth
    mytime birthtime;            // Time of birth
    double money;                 // Net worth in billions
    int *billCode;                // 11-digit validation code
    struct bilList *next;         // Pointer to next node
    struct bilList *prev;         // Pointer to previous node
} billionaire;


**Commands**
Command	Format	Description
newbil	newbil Name Surname;City/Country;Source;Birth Country;Gender;DD/MM/YYYY HH:MM;Billions;	Create new billionaire entry
sum	sum	Display total wealth of all billionaires
deleteN	deleteN	Remove the most recently added billionaire
deleteO	deleteO	Remove the oldest billionaire
save	save filename.txt	Save all records to file
load	load N filename.txt	Load N billionaires from file
exit	exit	Exit program (frees memory)

**Getting Started**
Prerequisites
GCC compiler

Terminal/Command Prompt

Installation
Clone the repository:

bash
git clone https://github.com/yourusername/billionaire-management-system.git
Navigate to the project directory:

bash
cd billionaire-management-system
Compile the program:

bash
gcc -o billionaire_manager KlianiTsouko.c
Run the program:

bash
./billionaire_manager

**Usage Examples**
Creating a new billionaire
text
$> newbil Elon Musk;USA;Tesla/SpaceX;South Africa;Male;28/06/1971 12:15;245.6;
Generated bill code: 47285936105
Viewing total wealth
text
$> sum
Total money of all billionaires: 245.60 billions
Saving to file
text
$> save billionaires.txt
Billionaires saved to billionaires.txt
Loading from file
text
$> load 5 billionaires.txt
Billionaires loaded from billionaires.txt

**Bill Code Generation**
The system automatically generates an 11-digit validation code for each billionaire using a modified Luhn algorithm:

First 10 digits: Random numbers with odd-position digits doubled

11th digit: Checksum calculated from the sum of first 10 digits

Validation: The code follows credit card number validation principles

Example output: 47285936105

**File Format**
Data is stored in plain text format using semicolons as delimiters:

text
Name;Location;Source;BirthCountry;Gender;DD/MM/YYYY;HH:MM;Money
Elon Musk;USA;Tesla/SpaceX;South Africa;Male;28/06/1971;12:15;245.60

**Compilation**
bash
# Standard compilation
gcc -o billionaire_manager KlianiTsouko.c

# With debugging symbols
gcc -g -o billionaire_manager KlianiTsouko.c

# With all warnings
gcc -Wall -Wextra -o billionaire_manager KlianiTsouko.c
