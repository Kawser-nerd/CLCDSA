n,a,b,*s=map(int,open(0).read().split())
M,m=max(s),min(s)
d=M-m
if not d:
    print(-1)
    exit()
p=b/d
q=a-sum(map(lambda x:p*x,s))/n
print(p,q)