n,a,b = map(int,input().split())
s=[int(input()) for i in range(n)]
s.sort()

d = s[-1]-s[0]
if d==0:
    if b == 0:
        print(0,a-s[0])
    else:
        print(-1)
    exit()
    
p = b/d


for i in range(n):
    s[i]=s[i]*p
    
q = (a*n-sum(s))/n
print(p,q)