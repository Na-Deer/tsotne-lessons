### Implementing a Simple Database System

**Objective**: Use structs and pointers to build a simple in-memory database for storing and querying records.

**Task**:
1. Define a `struct` named `Student` that has the following members:
   - `int id;`
   - `char name[100];` //
   - `float gpa;`

2. Create a `struct` named `Database` that has the following members:
   - `struct Student *students;` (a pointer to an array of `Student`)
   - `int count;` (number of students currently in the database)
   - `int capacity;` (maximum number of students the database can hold)

3. Implement the following functions:
   - `struct Database* createDatabase(int capacity);`  
     Creates a database with a specified capacity and returns a pointer to it.
   - `void addStudent(struct Database *db, int id, char name[], float gpa);`  
     Adds a student to the database. If the database is full, print an error message.
   - `struct Student* findStudentById(struct Database *db, int id);`  
     Searches for a student by ID and returns a pointer to the `Student` struct. If the student is not found, return `NULL`.
   - `void printStudent(struct Student *student);`  
     Prints the details of a student.

4. In `main`, create a database, add a few students, and then search for students by ID. If a student is found, print their details.

**Expected Output**:
```c
[INFO] Student added: ID=1, Name=John Doe, GPA=3.5
[INFO] Student added: ID=2, Name=Jane Smith, GPA=3.8
[INFO] Student added: ID=3, Name=Alice Johnson, GPA=3.7

[INFO] Searching for student with ID=2...
[INFO] Student found:
ID: 2
Name: Jane Smith
GPA: 3.8

[ERROR] Student with ID=4 not found.