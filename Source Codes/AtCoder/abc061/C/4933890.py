N,K = map(int,input().split())
dict = {}
for i in range(N):
  a,b = map(int,input().split())
  if(a in dict): dict[a] += b
  else: dict[a] = b

count = 0
ans = 0
for k, v in sorted(dict.items()):
   count += v
   if(count >= K): 
    ans = k
    break
print(ans)