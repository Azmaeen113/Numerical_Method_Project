GAUSS-JORDAN ELIMINATION METHOD

Theory:
The Gauss-Jordan elimination method is an extension of Gaussian elimination that transforms the augmented matrix into reduced row echelon form (RREF). Unlike Gauss elimination, it eliminates variables both above and below the pivot, directly producing the solution without back substitution.

Process:
1. Transform the augmented matrix to diagonal form with 1's on the diagonal
2. Read the solution directly from the last column

Algorithm:
1. Input the number of equations n
2. Input the augmented matrix [A|b]
3. For each column i from 0 to n-1:
   a. Find pivot (row with largest absolute value in column i)
   b. Swap current row with pivot row
   c. Divide entire pivot row by pivot element (make diagonal element 1)
   d. For all other rows r ≠ i:
      - Calculate factor f = a[r][i]
      - Subtract f times pivot row from row r
4. Solution is directly in the last column: x[i] = a[i][n]
5. Output the solution vector


