N = int(input())
NG = [int(input()) for i in range(3)]

for i in range(100):
  #print(N)
  if N in NG:
    break
  if N <= 3:
    N = 0
    break
  for j in [3, 2, 1]:
    if N - j not in NG:
      N -= j
      break

if N == 0:
  print('YES')
else:
  print('NO')