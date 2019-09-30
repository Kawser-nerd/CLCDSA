N = int(input())
a = [int(i) for i in input().split()]
ans = 0
for i in range(N):
  count = 0
  while a[i]%2 == 0:
    count += 1
    a[i] /= 2
  ans += count
print(ans)