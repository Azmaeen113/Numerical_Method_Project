MATRIX INVERSE METHOD (Using Adjoint and Determinant)

Theory:
A matrix inverse A⁻¹ is a matrix that, when multiplied with matrix A, gives the identity matrix. This method computes the inverse using the adjoint (adjugate) matrix and determinant. The inverse exists only if the determinant is non-zero.

Formula:
A⁻¹ = (1/det(A)) × adj(A)

where:
- det(A) is the determinant of matrix A
- adj(A) is the adjoint (transpose of cofactor matrix)

Algorithm:
1. Input the size n and matrix A
2. Calculate determinant of A:
   - Base case: n=1, det = A[0][0]
   - Base case: n=2, det = A[0][0]×A[1][1] - A[0][1]×A[1][0]
   - Recursive: det = Σ((-1)ⁱ × A[0][i] × det(Minor[0][i]))
3. If det = 0, output "Inverse Doesn't Exist" and exit
4. Calculate cofactor matrix:
   - For each element (i,j):
     - Minor[i][j] = submatrix with row i and column j removed
     - Cofactor[i][j] = (-1)^(i+j) × det(Minor[i][j])
5. Calculate adjoint:
   - adj[i][j] = Cofactor[j][i] (transpose of cofactor)
6. Calculate inverse:
   - A⁻¹[i][j] = adj[i][j] / det(A)
7. Output the inverse matrix


