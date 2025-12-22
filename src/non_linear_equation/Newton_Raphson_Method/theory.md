NEWTON-RAPHSON METHOD

Theory:
The Newton-Raphson method is one of the most powerful techniques for solving nonlinear equations. It uses the tangent line at the current approximation to find the next approximation. The method has quadratic convergence near the root, making it very fast when it converges.

Formula:
xₙ₊₁ = xₙ - f(xₙ)/f'(xₙ)

Geometric Interpretation:
The tangent line at point (xₙ, f(xₙ)) is drawn, and its x-intercept becomes the next approximation xₙ₊₁.

Algorithm:
1. Input polynomial degree and coefficients
2. Input initial guess x₀, tolerance, and max iterations
3. Define function f(x) and its derivative f'(x)
4. Newton-Raphson iteration:
   - Calculate f'(x₀)
   - If |f'(x₀)| < ε (very small): stop (derivative too small)
   - Calculate x₁ = x₀ - f(x₀)/f'(x₀)
   - If |x₁ - x₀| < tolerance or |f(x₁)| < tolerance: root found
   - Set x₀ = x₁
   - Repeat until convergence or max iterations
5. Output the root


