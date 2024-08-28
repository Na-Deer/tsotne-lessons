#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int* allocate_array(int numel){
    int* array = (int*)malloc(numel * sizeof(int));
    return array;
}


int random_int(){
    int int_min = 0; 
    int int_max = 10;

    return (int)((float)rand()/(float)RAND_MAX * 10);

}


void fill_array( int* array, int numel){
    for( int i = 0; i < numel; i++){
        array[i] = random_int();
    }
}

int print_array( int* array, int numel){
    for(int i = 0; i < numel; i++){
        printf("%i , ", array[i] );
    }
}


int main(){

    srand(time(NULL));

    int array_a_num = 2;
    int array_b_num = 3;



    int* array_a = allocate_array(array_a_num);
    int* array_b = allocate_array(array_b_num); 

    int* output_array = allocate_array(array_a_num * array_b_num);

    fill_array(array_a, array_a_num);
    fill_array(array_b, array_b_num);

    for( int i = 0; i < array_a_num;  i++){
        for( int j = 0; j < array_b_num; j++){
            output_array[ i * array_b_num + j] = array_a[i] * array_b[j];
        }
    }



    print_array(output_array, array_a_num *array_b_num);
    printf("\n");
    print_array(array_a, array_a_num);
    printf("\n");
    print_array(array_b, array_b_num);
    
    free(array_a);
    free(array_b);
    free(output_array);

}

