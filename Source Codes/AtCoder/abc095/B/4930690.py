n,x=map(int,input().split())
m=[int(input()) for i in range(n)]
ans=len(m)+(x-sum(m))//min(m)
print(ans)