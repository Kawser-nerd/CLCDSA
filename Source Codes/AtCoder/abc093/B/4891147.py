A, B, K = list(map(int, input().split()))

L = []

for i in range(A, min(A + K, B + 1)):
  L.append(i)

for i in range(max(B - K + 1, A + K), B + 1):
  L.append(i)

for i in L:
  print(i)