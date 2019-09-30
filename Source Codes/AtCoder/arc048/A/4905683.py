def f(x):
    if x<0:
        return x+1
    else:
        return x
A,B=map(int,input().split())
print(f(B)-f(A))