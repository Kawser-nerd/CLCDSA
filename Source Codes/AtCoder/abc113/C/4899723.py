N, M = map(int, input().split())
P_Y_i = [list(map(int, input().split())) for i in range(M)]
for i in range(M):
    P_Y_i[i].append(i)
Ken_index = [[] for i in range(N)]

for i in range(M):
    Ken_index[P_Y_i[i][0] - 1].append(P_Y_i[i])
for i in range(N):
    if len(Ken_index[i]) != 0:
        Ken_index[i].sort(key=lambda x: x[1])

Ken_Update = []
for Ken in Ken_index:
    for i in range(len(Ken)):
        Ken_Update.append(['{0:06d}'.format(Ken[i][0]) + '{0:06d}'.format(i+1), Ken[i][2]])

Ken_Update.sort(key=lambda x: x[1])

for i in range(len(Ken_Update)):
    print(Ken_Update[i][0])