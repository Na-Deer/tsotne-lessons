## Homework 2

Given a matrix of A and a matrix of B, write matrix multiplication function. Once the program is compiled I should be able to input the sizes of matrices.
So program should be runnable in the following way:

./program_name 100 300 300 20

which will result in me getting [100, 20] matrix in the end. If matrices are non-conformable, then program should print, "cant multiply matrices with these shapes"


Example:


#### A

[[2, 3, 1],

 [5, 4, 2],

 [10, 3, 2]]


#### B

[[1, 0, 0],

 [0, 1, 0],

 [0, 0, 1]]


#### C will be:
[[2, 3, 1],

 [5, 4, 2],

 [10, 3, 2]]

in C since we have 1D arrays we will have:
A = [2, 3, 1, 5, 4, 2, 10, 3, 2]

B = [1, 0, 0, 0, 1, 0, 0, 0, 1]

C = [2, 3, 1, 5, 4, 2, 10, 3, 2]
