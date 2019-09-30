*a,=map(int,input().split())
*b,=map(int,input().split())
print(sum(max(s,t)for s,t in zip(a,b)))