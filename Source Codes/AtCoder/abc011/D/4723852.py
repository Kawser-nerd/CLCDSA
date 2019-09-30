import math

def com(a, b):
	return math.factorial(a) // math.factorial(b) // math.factorial(a - b)

n, d = map(int, input().split())
x, y = map(int, input().split())

v, x_mod = x // d, x % d
w, y_mod = y // d, y % d

if x_mod != 0 or y_mod != 0:
    print(0)
else:
    pattern = 0
    
    for i in range(abs(v), n - abs(w) + 1, 2):
    	if (n - i + w) % 2 == 0:
            pattern += com(n, i) * com(i, (i + abs(v)) // 2) * com(n - i, (n - i + abs(w)) // 2)
    
    print(pattern / (4 ** n))