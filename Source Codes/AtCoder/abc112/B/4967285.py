n,l=map(int,input().split())
ans=999999
for _ in range(n):
  c,t=map(int,input().split())
  if t<=l:
    if c<ans:
      ans=c
if ans==999999:
  print('TLE')
else:
  print(ans)