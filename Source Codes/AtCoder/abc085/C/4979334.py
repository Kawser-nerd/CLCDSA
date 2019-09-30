def find(n, y):
  for i in range(n+1):
    for j in range(n+1-i):
      if 10000 * i + 5000 * j + 1000 * (n - i - j) == y:
        return i, j, n-i-j
  return -1, -1, -1
N, Y = map(int, input().split())
i, j, k = find(N, Y)
print("{} {} {}".format(i, j, k))