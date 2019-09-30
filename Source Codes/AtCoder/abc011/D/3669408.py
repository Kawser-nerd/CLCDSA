from math import factorial
N, D = map(int, input().split())
X, Y = map(int, input().split())
if X % D !=0 or Y % D != 0:
    print(0)
    exit()
y = 0
a = abs(X // D)
c = abs(Y // D)
fct = factorial(N)
if (N - a- c) % 2:
    print(0)
    exit()
m  = (N-a-c)//2
for b in range(m+1):
    y += fct//(factorial(a+b)*factorial(b)*factorial(c+m-b)*factorial(m-b))    
z = 4**N
print(y/z)