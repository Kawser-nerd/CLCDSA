n=int(input())
s=set()
ans=0
for _ in range(n):
  a=int(input())
  if a not in s:
    s.add(a)
  else:
    ans+=1
print(ans)