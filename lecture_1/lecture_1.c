#include "stdlib.h"
#include "stdio.h"

void allocate_memory(int a){
    int* some_dynamic_array = (int*)malloc(a * sizeof(int));
    free(some_dynamic_array);
}

void fill_array(int* array, int number, int num_elements){
    for (int i = 0; i < num_elements; i++){
        array[i] = number;
    }
}

void multiply_array(int* array, int number, int num_elements){
    for (int i = 0; i < num_elements; i++){
        array[i] = array[i] * number;
    }
}

void print_array(int* array, int num_elements){
    for (int i = 0; i < num_elements; i++){
        printf("%i", array[i]);
        printf("\n");
    }
}

void showoff_conditionals(int a, int b){
    // plain if
    if (a > 100) {
        printf("More than 100\n");
    } else if (a >= 50) {
        printf("MORE THAN 50\n");
    } else {
        printf("LESS THAN 50\n");
    }

    // and statement
    if (a > 100 && b < 150){
        printf("SOMETHING!\n");
    }

    // or statement
    if (a > 100 || b < 150){
        printf("OR SOMETHING!!\n");
    }
}

void showoff_loops(int a){
    // basic for
    for (int j = 0; j < a; j++){
        printf("%i\n", j);
    }
    // for with jumps
    for (int j = 0; j < a; j += 3){
        printf("%i\n", j);
    }

    // while
    int i = 0;
    while (i < 100){
        printf("%i\n", i);
        i += 2; // igivea rac i = i + 2;
    }
}

int multiply(int a, int b) {
    return a * b;
}

float multiply_f(float a, float b){
    return a * b;
}

int main() {
    printf("Hello world!\n");
    // data types
    int a = 100;
    int b = 150;
    float c = 50.5;
    char d = 'a';
    double e = 50.555555555555555;
    // printing int
    printf("A IS %i %i\n", a, b);
    // printing char
    printf("CHAR IS %c\n", d);
    // printing float
    printf("FLOAT IS %f\n", c);
    // printing float by indicating precision
    printf("FLOAT IS %.1f\n", c);
    // function calling
    printf("Multiplied %i\n", multiply(5, 10));
    printf("%.3f\n", multiply_f(5.5, 3.2));

    // conditionals
    showoff_conditionals(150, 500);
    // loop
    showoff_loops(100);

    // only declare variable
    int some_var;
    printf("%i\n", some_var);
    // strings
    char* some_string = "tsotne";
    for (int i = 0; i < 6; i++){
        printf("%c", some_string[i]);
    }
    printf("\n");
    // int modification
    int some_int = 100;
    printf("%i\n", some_int);
    some_int = 50;
    printf("%i\n", some_int);
    
    // pointers
    int foo = 100;
    int* foo_p;
    foo_p = &foo;
    printf("%p\n", &foo_p);
    printf("%p\n", foo_p);
    printf("%p\n", &foo);

    // arrays - static allocation
    int some_array[10];
    some_array[1] = 100;
    printf("%i\n", some_array[1]);
    
    // arrays - dynamic allocation
    // for (int i = 0; i < 100000000000000; i++){
    //     allocate_memory(10000000);
    // }
    int num_elements = 100;
    int* arr = (int*)malloc(num_elements * sizeof(int));
    fill_array(arr, 1, num_elements);
    multiply_array(arr, 2, num_elements);
    print_array(arr, num_elements);
}
