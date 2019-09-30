n,h=map(int,input().split())
a,b,c,d,e=map(int,input().split())
k=float("inf")
for i in range(n+1):
    s=max(0,(e*n-(b+e)*i-h)//(d+e)+1)
    if s+i<=n:
        k=min(a*i+c*s,k)
print(k)