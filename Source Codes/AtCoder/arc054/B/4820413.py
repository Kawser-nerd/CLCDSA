p=float(input())
def f(x):
    return x+p/(2**(x/1.5))
s=100
l=0
while s-l>10**(-12):
    a=(s+l*2)/3
    b=(s*2+l)/3
    if f(a)<f(b):
        s=b
    else:
        l=a
print(f(s))