#include <stdio.h>
#include <stdlib.h>

int* allocate_array(int numel){
    int* array = (int*)malloc(numel * sizeof(int));
    return array;
}


struct student {
    int id;
    char name[100];
    float gpa;
};


struct database{
    struct student *students;
    int count;
    int capacity;
};


struct database* createDatabase(int capacity){

    struct database* database = (struct database*)malloc(sizeof(struct database));

    struct student* students = (struct student*)malloc(capacity * sizeof(struct student));

    database -> students = students;

};


void addStudent(struct database* database, int id, char name[], float gpa){
    
    struct student* new_student = (struct student*)malloc(sizeof(struct student));

    new_student -> id = id;
    //new_student -> name = name;
    new_student -> gpa = gpa;

    database -> students[database -> count]= *new_student;

    database -> count = database -> count + 1;
}; 


void print_student(struct student print_student){

    printf("id - %i ", print_student.id);
    //printf("name - %i", print_student -> id);
    printf("gpa - %f\n", print_student.gpa);

}


struct student* find_student( struct database* db, int id ){

    int currentcount = db -> count;


    for( int i = 0; i < currentcount; i++ ){
        if ( db -> students[i].id == id) {

            
            return &db -> students[i];
        }
    }
}

void print_array( int* array, int numel){
    for(int i = 0; i < numel; i++){
        printf("%i , ", array[i] );
    }
}


void FindStudentWithHigherGpa(struct database* db, float gpaTarget){

    int counter = 0;

    int* IdArray = (int*)malloc( db-> count * sizeof(int));

    for( int i = 0 ; i < db -> count; i++ ){

        if( db -> students[i].gpa > gpaTarget){

            IdArray[counter] = db -> students[i].id;

            counter++;
        }

    }


    print_array(IdArray, counter);

    free(IdArray);

}


int main(){

    struct database* db1 = createDatabase(10);

    addStudent(db1, 1, "Irakli Salia", 3.9);

    addStudent(db1, 2, "Tsotne Nadiradze", 1.5);

    
    addStudent(db1, 3, "Nika Salia", 3.8);

    addStudent(db1, 4, "Gvantsa Nadiradze", 3.2);



    print_student( db1 -> students[0]);

    print_student( db1 -> students[1]);

    //printf("location %p\n", find_student(db1, 2));

    //printf("location %p\n", &db1->students[1]);

    float targetGpa = 2;

    FindStudentWithHigherGpa(db1, targetGpa);

    
    free(db1);
}

/*
extend the database homework with a function called findStudentsWithHigherGPA

where function receives float gpa and it gives back an array of all student ids 
who have gpa more than or equal that gpa 


example there are 3 students:
A
B
C
with gpas:
1.2
3.2
2.5


if I pass in to the function 2.5 it should give me an array of student ids of students with B and C
*/