from scipy import optimize
import numpy as np
np.set_printoptions(precision=15)

a, b, c = map(int, input().split())

def f(x):
	return a*x + b*np.sin(c*np.pi*x) - 100

#ans = optimize.fsolve(f, 1.6, xtol=1e-8, maxfev=500, full_output=True)
ans = optimize.newton(f, 0)

print(ans)