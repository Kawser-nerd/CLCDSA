import copy

AB = input().split()
Ans = [0, 0]
AB[0] = str(int(AB[0]) - 1)
for i in range(2):
  Dset = [2, 2, len(AB[i]) + 1]
  D = 0
  for j in range(3):
    D = [copy.deepcopy(D) for k in range(Dset[j])]
  D[0][1][0] = 1
  for j in range(len(AB[i])):
    t = int(AB[i][j])
    if t < 4: a, b, c, d =  (t, 0, 1, 0)
    elif t == 4: a, b, c, d =  (4, 0, 0, 1)
    elif t < 9: a, b, c, d = (t - 1, 1, 1, 0)
    else: a, b, c, d = (8, 1, 0, 1)
    D[j + 1][0][0] = D[j][0][0] * 8 + D[j][1][0] * a
    D[j + 1][0][1] = D[j][0][0] * 2 + D[j][0][1] * 10 \
                   + D[j][1][0] * b + D[j][1][1] * t
    D[j + 1][1][0] = D[j][1][0] * c
    D[j + 1][1][1] = D[j][1][0] * d + D[j][1][1]
  Ans[i] = D[-1][0][1] + D[-1][1][1]

print(Ans[1] - Ans[0])