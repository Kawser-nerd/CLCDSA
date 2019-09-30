n = int(input())
alist = list(map(int, input().split()))
preva = None
ans = 0
for a in alist:
  if preva is None:
    preva = a
  else:
    if preva == a:
      ans += 1
      preva = None
    else:
      preva = a
print(ans)