SECANT METHOD

Theory:
The Secant method is a root-finding algorithm that uses a succession of roots of secant lines to approximate a root of a function. It's similar to Newton-Raphson but doesn't require the derivative. Instead, it approximates the derivative using two previous points, making it more practical when derivatives are difficult to compute.

Formula:
xₙ₊₁ = xₙ - f(xₙ) · (xₙ - xₙ₋₁) / (f(xₙ) - f(xₙ₋₁))

This is derived from the slope of the secant line through (xₙ₋₁, f(xₙ₋₁)) and (xₙ, f(xₙ)).

Algorithm:
1. Input polynomial degree and coefficients
2. Input two initial guesses x₀ and x₁
3. Input tolerance and max iterations
4. Calculate f(x₀) and f(x₁)
5. Secant iteration:
   - Check if |f(x₁) - f(x₀)| is too small (avoid division by zero)
   - Calculate x₂ = x₁ - f(x₁)·(x₁ - x₀)/(f(x₁) - f(x₀))
   - Calculate f(x₂)
   - If |x₂ - x₁| < tolerance or |f(x₂)| < tolerance: root found
   - Update: x₀ = x₁, f(x₀) = f(x₁)
   - Update: x₁ = x₂, f(x₁) = f(x₂)
   - Repeat until convergence or max iterations
6. Output the root


