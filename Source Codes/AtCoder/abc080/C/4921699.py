n=int(input())
f=[list(map(int,input().split())) for i in range(n)]
p=[list(map(int,input().split())) for i in range(n)]
ans=-10**9
for i in range(1,2**10):
  a=0
  m=[i%2,i//2%2,i//4%2,i//8%2,i//16%2,i//32%2,i//64%2,i//128%2,i//256%2,i//512%2]
  mm=[0 for i in range(n)]
  for i in range(10):
    for j in range(n):
      if m[i]==1 and f[j][i]==1:
        mm[j]+=1
  for i in range(n):
    a+=p[i][mm[i]]
  ans=max(ans,a)
print(ans)