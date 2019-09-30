N, M, C = map(int, input().split())
B = list(map(int, input().split()))
A = []

AC_codes = 0

for _ in range(N):
  A.append(list(map(int, input().split())))

for i in A:
  for j in range(len(B)):
    i[j] = i[j] * B[j]
  if sum(i) + C > 0:
    AC_codes += 1
print(AC_codes)