A, B, K = map(int, input().split())
min = min(A + K -1, B)
max = max(A + K, B - K + 1)
for i in range(A, min + 1):
  print(i)
for i in range(max, B + 1):
  print(i)