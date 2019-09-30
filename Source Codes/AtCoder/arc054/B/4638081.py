p=float(input())

def func(t):
    return t+p/(2**(t/1.5))

def TernarySearch(f,xmin,xmax):
    x0=xmin
    x3=xmax
    while x3-x0>10**(-12):
        x1=(x0*2+x3)/3
        x2=(x0+x3*2)/3
        if f(x1)<f(x2):
            x3=x2
        else:
            x0=x1
    return x3

print(func(TernarySearch(func,0,100)))