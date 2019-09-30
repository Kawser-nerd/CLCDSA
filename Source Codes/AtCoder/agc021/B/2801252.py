import math
N = int(input())
H = [list(map(int, input().split())) for i in range(N)]
P = [[0, 2*math.pi] for i in range(N)]
for i in range(N):
    for j in range(N):
        if i==j:
            continue
        rad = math.atan2(H[i][1]-H[j][1], H[i][0]-H[j][0])
        mi = (rad - math.pi/2) % (2*math.pi)
        ma = (rad + math.pi/2) % (2*math.pi)
        if ma > mi:
            if P[i][0] >= P[i][1]:
                if mi < P[i][1]:
                    P[i] = [mi, P[i][1]]
                elif ma > P[i][0]:
                    P[i] = [P[i][0], ma]
                else:
                    P[i] = [0, 0]
                    break
            else:
                P[i] = [max(P[i][0], mi), min(P[i][1], ma)]
                if P[i][0] >= P[i][1]:
                    P[i] = [0, 0]
                    break
        else:
            if P[i][0] >= P[i][1]:
                P[i] = [max(P[i][0], mi), min(P[i][1], ma)]
            elif P[i] == [0, 2*math.pi]:
                P[i] = [mi, ma]
            else:
                if mi < P[i][1]:
                    if mi < P[i][0]:
                        continue
                    else:
                        P[i] = [mi, P[i][1]]
                elif ma > P[i][0]:
                    if ma > P[i][1]:
                        continue
                    else:
                        P[i] = [P[i][0], ma]
                else:
                    P[i] = [0, 0]
                    break
for p in P:
    print((p[1]-p[0]) / (2*math.pi) % 1)