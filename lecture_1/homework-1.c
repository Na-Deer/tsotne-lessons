#include "stdlib.h"
#include "stdio.h"

// there are three possible scenarios

// 1. complete miss
// 2. partial encompass
// 3. total encompass 

// to save time we first identify which one we are dealing with 

// we take one rectangle from any array and check if any of its coordinates are inside the other one 

// does not matter which one we check since the outcome will be same 


float random_float(){

    float min = 0.0f;
    float max = 1000.0f;

    return min + (float)rand() / (float)RAND_MAX * (max - min);
}


float rectangle_create(int position, float* rect_array ){

    float ax = random_float();
    float ay = random_float();

    float bx = ax + random_float();
    float by = ay;

    float cx = bx; 
    float cy = by + random_float();

    float dx = ax;
    float dy = cy; 

    rect_array[0 + position * 8] = ax; 
    rect_array[1 + position * 8] = ay; 
    rect_array[2 + position * 8] = bx; 
    rect_array[3 + position * 8] = by; 
    rect_array[4 + position * 8] = cx; 
    rect_array[5 + position * 8] = cy; 
    rect_array[6 + position * 8] = dx; 
    rect_array[7 + position * 8] = dy; 

}



float max(float a, float b){
    if (a > b) {
        return a; 
    }
    
    return b;
}

float min(float a, float b){
    if (a > b){
        return b;
    }
    
    return a;
    
}



void print_array(float* array, int num_elements){
    for (int i = 0; i < num_elements; i++){
        printf("%f", array[i]);
        printf("\n");
    }
}



float intersection_area(float* a, float* b, int position_a, int position_b){

    int stride_a = position_a * 8;
    int stride_b = position_b * 8;

    float min_x = max( a[1 + stride_a], b[1 + stride_b]);
    float min_y = max( a[0 + stride_a], b[0 + stride_b]);

    float max_x = min( a[4 + stride_a], b[4 + stride_b]);
    float max_y = min( a[5 + stride_a], b[5 + stride_b]);

    if ((max_x - min_x < 0) || (max_y - min_y < 0)){
        return 0;
    }
        return (max_x - min_x) * (max_y - min_y);
    
}

float calc_area(float* rectangle, int position){
    
    int stride = position * 8;

    return (rectangle[4 + stride] - rectangle[0 + stride]) 
            * 
           (rectangle[5 + stride] - rectangle[1 + stride]);
}



float union_area( float* a, float* b, float intersection_area, int position_a, int position_b){

    return calc_area(a, position_a) + calc_area(b, position_b) - intersection_area;
}

float main() {

    float* array_a = (float*)malloc( 16 * sizeof(float));

    float* array_b = (float*)malloc( 24 * sizeof(float));

    float* output_array = (float*)malloc( 6 * sizeof(float));

    for( int i = 0; i < 2; i++){
        rectangle_create(i, array_a);
    }

    for( int i = 0; i < 3; i++){
        rectangle_create(i, array_b);
    }
    array_a[8] = 0.0f;
    array_a[9] = 0.0f;
    array_a[10] = 100.0f;
    array_a[11] = 0.0f;
    array_a[12] = 100.0f;
    array_a[13] = 100.0f;
    array_a[14] = 0.0f;
    array_a[15] = 100.0f;

    array_b[0] = 0.0f;
    array_b[1] = 0.0f;
    array_b[2] = 50.0f;
    array_b[3] = 0.0f;
    array_b[4] = 50.0f;
    array_b[5] = 50.0f;
    array_b[6] = 0.0f;
    array_b[7] = 50.0f;

    for( int i = 0; i < 2; i++ ){
        for( int j = 0; j < 3; j++ ){            
            float intersection_AB = intersection_area(array_a, array_b, i , j );
            float union_AB = union_area( array_a, array_b, intersection_AB, i , j);
            float answer = intersection_AB / union_AB;

            output_array[j + i * 3] = answer;
        }
    }

    print_array(output_array, 6);
    free(array_a);
    free(array_b);
}