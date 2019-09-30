n=int(input())
b=[int(input()) for i in range(n-1)]
def f(x):
    c=[]
    for i in range(n-1):
        if b[i]==x:
            c.append(i)
    if len(c)==0:
        return 1
    else:
        d=[]
        for i in c:
            d.append(f(i+2))
        return max(d)+min(d)+1
print(f(1))