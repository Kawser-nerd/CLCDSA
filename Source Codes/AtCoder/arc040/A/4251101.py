N = int(input())
L = []
for i in range(N):
  L.append(input())
r = 0
b = 0
for i in range(N):
  for j in range(N):
    if L[i][j] == 'R':
      r += 1
    elif L[i][j] == 'B':
      b += 1
    else:
      None
if r > b:
  print('TAKAHASHI')
elif r < b:
  print('AOKI')
else:
  print('DRAW')