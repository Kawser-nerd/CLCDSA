n = int(input())
ans = -1
X = [None] * n
Y = [None] * n
for i in range(n):
  X[i], Y[i] = map(int, input().split())

for i in range(n - 1):
  for j in range(i + 1, n):
    if (ans < ((X[j] - X[i]) ** 2 + (Y[j] - Y[i]) ** 2) ** 0.5):
      ans = ((X[j] - X[i]) ** 2 + (Y[j] - Y[i]) ** 2) ** 0.5

print(ans)