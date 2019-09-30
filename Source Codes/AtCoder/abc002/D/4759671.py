N, M = list(map(int, input().split(' ')))
R = [[0] * N for _ in range(N)]
for i in range(M):
  x, y = list(map(int, input().split(' ')))
  R[x-1][y-1] = R[y-1][x-1] = 1
# # # # # # # # # # #
G = []
for person in range(N):
  group = [person]
  for i in range(N):
    for g in group:
      flag = True
      if R[g][i] != 1:
        flag = False
        break
    if flag:
      group.append(i)
  G.append(group)
print(max(list(map(lambda x: len(x), G))))