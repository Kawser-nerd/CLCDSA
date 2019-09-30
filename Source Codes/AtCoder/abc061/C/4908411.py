n, k = map(int, input().split())
count = 0
ab = [list(map(int, input().split())) for _ in range(n)]
ab = sorted(ab)
i = 0
while count < k:
  a, b = ab[i]
  count += b
  i += 1
  if count >= k:
    print(a)
    break