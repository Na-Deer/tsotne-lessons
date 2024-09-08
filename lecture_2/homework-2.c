#include "stdlib.h"
#include "stdio.h"
#include <time.h>


int* allocate_array(int numel){
    int* array = (int*)malloc(numel * sizeof(int));
    return array;
}


int random_int(){
    
    int min = 1;
    int max = 10;

    return rand() % (max + 1);
    

    //return 1; 
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

int print_matrice( int* array, int numel, int stride){

            printf("\n");

    for(int i = 0; i < numel; i++){
        if (i == 0) {
            printf("[%i ,", array[i]);
        } else if ( i == numel - 1) {
            printf("%i]", array[i]);

        } else if( (i + 1) % stride == 0) {
            printf("%i , \n", array[i] );

        } else {
            printf("%i , ", array[i] );
        }
    };
             printf("\n");
}



int matrice_single_multiplier( int* m_1, int matr_1_row_num, int matr_1stride, 
                               int* m_2, int matr_2_col_num, int matr_2stride,
                               int numel
                             ){

    
    int* multiplication = allocate_array(numel);

    for( int i = 0; i < numel; i++){
        multiplication[i] = m_1[ i + ((matr_1_row_num - 1) * matr_1stride)]
                            *
                            m_2[matr_2_col_num + i * matr_2stride - 1];
                                          
    };

    int multiplication_summed = 0;

    for (int i = 0; i < numel; i++){
        multiplication_summed += multiplication[i];
    };

    return multiplication_summed;

    free(multiplication);

}

int * matrice_multiplier( int* m_1, int m_1a, int m_1b, int matr_1stride, 
                        int* m_2, int m_2a, int m_2b, int matr_2stride
                      ){

                int numel = m_1a * m_2b;
                
                int* final_matrice = allocate_array(numel);    

    for(int i = 0; i < numel; i++ ){

        int row_num = (i / matr_2stride ) + 1;
        int col_num = i % matr_2stride + 1;


        final_matrice[i] = matrice_single_multiplier(m_1, row_num, matr_1stride,
                                                     m_2, col_num, matr_2stride, m_1b);
        ;

        
    }

    return final_matrice;
}







int main(){

    srand(time(NULL));

    int m_1a = 1;
    int m_1b = 1;

    int m_2a = 1;
    int m_2b = 1;

    int m_1_total_num = m_1a * m_1b;
    int m_2_total_num = m_2a * m_2b;

    int* m_1 = allocate_array(m_1_total_num);
    int* m_2 = allocate_array(m_2_total_num); 

    int* m_output = allocate_array(m_1a * m_2b);

    fill_array(m_1, m_1_total_num);
    fill_array(m_2, m_2_total_num);

    int m_1_stride = m_1b;
    int m_2_stride = m_2b;

    


    //print_array(m_1, m_1_total_num);
    print_matrice(m_1, m_1_total_num, m_1_stride);
    print_matrice(m_2, m_2_total_num, m_2_stride);
    printf("\n");

    printf(" answer %i", 
    matrice_single_multiplier(m_1, 1, m_1_stride,
                              m_2, 1, m_2_stride, m_1b)

    );

   

    int * output_array =  matrice_multiplier( m_1, m_1a, m_1b, m_1_stride,
                                              m_2, m_2a, m_2b, m_2_stride);

    print_matrice(output_array, m_1a * m_2b, m_2b);

    free(output_array);





    int check = 6;

    int row = (check / m_2_stride) + 1;

    int col = check % m_2_stride + 1;

    printf( " row is %i\n", row);
    printf( " col is %i\n", col);

    printf( "multiply is %i\n",
    matrice_single_multiplier(m_1, row, m_1_stride,
                              m_2, col, m_2_stride, m_1b)
    );


    printf("%i\n", m_1a * m_2b);



    int numel = m_1b;

    int matr_1_row_num = row;
    int matr_2_col_num = col;

    int matr_1stride = m_1_stride;
    int matr_2stride = m_2_stride;
    
    int* multiplication = allocate_array(numel);

    for( int i = 0; i < numel; i++){
        multiplication[i] = m_1[ i + ((matr_1_row_num - 1) * matr_1stride)]
                            *
                            m_2[matr_2_col_num + i * matr_2stride - 1];
                                          
    };





    int multiplication_summed = 0;

    for (int i = 0; i < numel; i++){
        multiplication_summed += multiplication[i];
    };

    print_array(multiplication, numel);

    printf("print %i\n", m_1[3 + ((1 - 1) * matr_1stride)]);

    printf("print %i\n", m_2[7]);

    printf("mult is %i\n", multiplication_summed);

    //free(multiplication);

    free(m_1);
    free(m_2);
    free(m_output);



}