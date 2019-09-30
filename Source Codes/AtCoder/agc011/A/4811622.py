n, c, k = map(int, input().split())
t = [int(input()) for i in range(n)]
t.sort()

result = 1
count = 0
f = 0

for i in range(n):
  if (t[i] - t[f]) > k or c == count:
    result += 1
    count = 1
    f = i
  else:
    count += 1
print(result)