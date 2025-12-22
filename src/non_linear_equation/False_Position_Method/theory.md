FALSE POSITION METHOD (Regula Falsi)

Theory:
The false position method (Regula Falsi) is a root-finding algorithm that combines the reliability of the bisection method with faster convergence. Instead of bisecting the interval, it uses linear interpolation to approximate the root. A straight line is drawn between points (a, f(a)) and (b, f(b)), and the x-intercept of this line becomes the next approximation.

Formula:
c = (a·f(b) - b·f(a)) / (f(b) - f(a))

This is derived from the equation of a line passing through (a, f(a)) and (b, f(b)).

Algorithm:
1. Input polynomial degree and coefficients
2. Input initial point a, second point b, step size, tolerance, max iterations
3. Find bracketing interval [a, b] where f(a) × f(b) < 0
4. Calculate f(a) and f(b)
5. False position iteration:
   - Calculate c = (a·f(b) - b·f(a)) / (f(b) - f(a))
   - Calculate f(c)
   - If |f(c) - prev| ≤ tolerance or |f(c)| < tolerance: root found
   - If f(a) × f(c) < 0: set b = c, f(b) = f(c)
   - Else: set a = c, f(a) = f(c)
   - Store f(c) as prev
   - Repeat until convergence or max iterations
6. Output the root


