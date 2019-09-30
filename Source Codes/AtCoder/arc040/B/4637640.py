n, k = map(int,input().split())
s = input()[::-1]
cnt = 0
ff = s.find(".")
cost = max(n-ff-k, 0)
if ff == -1:
  cost = 0
while s:
  f = s.find(".")
  if f == -1:
    break
  s = s[f+k:]
  cnt += 1
print(cnt+cost)