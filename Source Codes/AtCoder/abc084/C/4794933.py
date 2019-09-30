n = int(input())
c = []
s = []
f = []

for i in range(n-1):
    ci,si,fi = map(int,input().split())
    c.append(ci)
    s.append(si)
    f.append(fi)
def time(t,i):
    if s[i] >= t:
        T = s[i]
    else:
        if(t-s[i])%f[i]==0:
            T = t
        else:
            T = t+f[i] -(t-s[i])%f[i]
    return T+c[i]
for i in range(n):
    t = 0
    for j in range(i,n-1):
        t = time(t,j)
    print(t)