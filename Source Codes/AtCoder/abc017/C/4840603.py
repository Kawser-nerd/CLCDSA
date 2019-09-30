n,m=map(int,input().split())
l_r_s=[list(map(int,input().split())) for _ in range(n)]
f=[0 for _ in range(m+2)]
for i in range(n):
  f[l_r_s[i][0]]+=l_r_s[i][2]
  f[l_r_s[i][1]+1]-=l_r_s[i][2]
a=float('inf')
for i in range(1,m+1):
  f[i]+=f[i-1]
  a=min(f[i],a)
print(sum([x[2] for x in l_r_s])-a)