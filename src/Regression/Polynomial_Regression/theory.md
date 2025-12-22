POLYNOMIAL REGRESSION (2nd Degree / Quadratic)

Theory:
Polynomial regression extends linear regression by fitting a polynomial curve to data points. A second-degree polynomial (quadratic) regression fits a parabola y = a + bx + cx² to the data. This method uses the least squares approach to determine the coefficients that minimize the sum of squared errors.

Equation:
y = a + bx + cx²

where:
- a is the constant term
- b is the linear coefficient
- c is the quadratic coefficient

Normal Equations:
n·a + (Σx)·b + (Σx²)·c = Σy
(Σx)·a + (Σx²)·b + (Σx³)·c = Σxy
(Σx²)·a + (Σx³)·b + (Σx⁴)·c = Σx²y

Algorithm:
1. Input number of data points n
2. Input x and y values for all data points
3. Calculate summations:
   - Σx, Σx², Σx³, Σx⁴ (power sums of x)
   - Σy, Σxy, Σx²y (weighted sums)
4. Form augmented matrix from normal equations
5. Solve system using Gauss-Jordan elimination:
   - Convert to reduced row echelon form
   - Extract coefficients a, b, c
6. Input value v where prediction is needed
7. Calculate: result = a + b×v + c×v²
8. Output the predicted value


