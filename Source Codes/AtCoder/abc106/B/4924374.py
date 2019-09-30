N = int(input())
ans = 0
for a in range(1,N+1):
  if a%2==0:
    continue
  c = 0
  for b in range(1,a+1):
    if a % b == 0:
      c += 1
  if c == 8:
    ans += 1
print(ans)