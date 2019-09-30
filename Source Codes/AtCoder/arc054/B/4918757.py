import sys
input = sys.stdin.readline


p = float(input())

def f(x):
    return x+p/2**(x/1.5)

high = 100
low = 0
while high - low > 0.000000001:
    mid_left = high/3+low*2/3
    mid_right = high*2/3+low/3
    if f(mid_left) >= f(mid_right):
        low = mid_left
    else:
        high = mid_right
print(f(high))