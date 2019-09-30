N=int(input())
res = 0
for i in range(N):
  a,b=map(int,input().split())
  res += b-a+1
print(res)