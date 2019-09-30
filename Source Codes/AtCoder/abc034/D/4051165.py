def c(x):
    y = [0]*n
    for i in range(n):
        y[i]=v[i]-x*w[i]/100.0
    y.sort()
    tmp = 0
    for i in range(k):
        tmp += y[n-1-i]
    if tmp>=0:
        return True
    else:
        return False

n,k = map(int,input().split())
w = [0.0]*n
v = [0.0]*n
for i in range(n):
    x,y = map(float,input().split())
    w[i] = x
    v[i] = x*y/100.0

a = 0.0
b = 100.0
for i in range(100):
    m = (a+b)/2
    if c(m):
        a = m
    else:
        b = m
print(m)