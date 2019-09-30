n = int(input())
a = list(map(int,input().split()))
ans = 0
while True:
  for i in range(n):
    b = a[i]
    c = b//n
    b = b%n
    a[i] = b
    for j in range(n):
      if j == i:
        continue
      a[j] += c
    ans += c
  if max(a) < n:
    break
print(ans)