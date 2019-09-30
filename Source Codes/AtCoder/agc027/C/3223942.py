import collections

n,m = map(int,input().split())
s = list(str(input()))
key = collections.deque()
lis = [[] for i in range(n)]
li = [{"A":0,"B":0} for i in range(n)]

for i in range(m):
  a,b = map(int,input().split())
  lis[a-1].append(b-1)
  lis[b-1].append(a-1)
  li[a-1][s[b-1]] += 1
  li[b-1][s[a-1]] += 1
  
ans = [0 for i in range(n)]

for i in range(n):
  if li[i]["A"] == 0 or li[i]["B"] == 0:
    key.append(i)
    ans[i] = 1
    
while len(key) > 0:
  num = key.popleft()
  for nu in lis[num]:
    li[nu][s[num]] -= 1
    if li[nu]["A"] == 0 or li[nu]["B"] == 0:
      if ans[nu] == 0:
        key.append(nu)
        ans[nu] = 1

if sum(ans) == n:print("No")
else:print("Yes")