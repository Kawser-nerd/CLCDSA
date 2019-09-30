N = int(input())
P = [int(input()) for i in range(N)]

T = [0] * (N + 1)
for i in P:
  if T[i - 1] == 0:
    T[i] = -1
  elif T[i - 1] < 0:
    T[i - 1] -= 1
    T[i] = i - 1
  else:
    T[T[i - 1]] -= 1
    T[i] = T[i - 1]

print(N + min(T))