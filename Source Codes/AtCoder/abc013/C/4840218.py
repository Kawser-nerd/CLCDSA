import math

N, H = map(int, input().split())
A, B, C, D, E = map(int, input().split())
min = float('inf')
for i in range(N + 1):
  tmp1 = H + (B + E) * i - E * N
  j = math.ceil(-1 * tmp1 / (D + E))
  if j < 0:
    j = 0
  if tmp1 + (D + E) * j == 0:
    j += 1
  tmp2 = A * i + C * j
  #print("{0} {1} {2}".format(i, j, tmp2))
  if tmp2 < min:
    min = tmp2
  if j == 0:
    break

print(min)