## Homework 1

Given an array of A and an array of B, where A is an array of (x,y) coordinates and B is an array of (x,y) coordinates each being of shape [M * 8] and [N * 8]calculate array C, which will be of shape [M * N] where each element is an intersection area divided by union area of box from array of A and box from array of B

Example:


#### A


[0, 0, 100, 0, 100, 100, 0, 100, 200, 200, 300, 200, 300, 300, 200, 300]


#### B


[0, 0, 50, 0, 50, 50, 0, 50, 0, 0, 50, 0, 50, 50, 0, 50 ]


#### C will be:


[0.25, 0.25, 0.0, 0.0]