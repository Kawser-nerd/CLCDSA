n,a,b=map(int,input().split())
s=[int(input()) for i in range(n)]
M,m=max(s),min(s)
d=M-m
if not d:
    print(-1)
    exit()
p=b/d
q=a-sum(s)*p/n
print(p,q)