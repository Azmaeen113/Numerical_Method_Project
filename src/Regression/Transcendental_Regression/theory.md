TRANSCENDENTAL REGRESSION (Exponential Model)

Theory:
Transcendental regression fits data to an exponential function y = ae^(bx). This method is used when the relationship between variables follows exponential growth or decay. By taking the logarithm of both sides, the exponential model is transformed into a linear form, allowing us to use linear regression techniques.

Exponential Equation:
y = a·e^(bx)

Taking natural logarithm:
ln(y) = ln(a) + bx

This becomes a linear equation: Y = C + bx
where Y = ln(y) and C = ln(a)

Formulas:
After applying linear regression to (x, ln(y)):
b = (n·Σ(x·ln(y)) - Σx·Σln(y)) / (n·Σ(x²) - (Σx)²)
C = (Σln(y) - b·Σx) / n
a = e^C

Algorithm:
1. Input number of data points n
2. Input x and y values for all data points
3. Calculate summations:
   - Σx = sum of x values
   - Σln(y) = sum of natural logarithms of y
   - Σ(x·ln(y)) = sum of products x[i]×ln(y[i])
   - Σ(x²) = sum of squares x[i]²
4. Calculate slope b using formula
5. Calculate intercept C using formula
6. Calculate a = e^C
7. Input value v where prediction is needed
8. Calculate: result = a·e^(b×v) = e^C·e^(b×v)
9. Output the predicted value


