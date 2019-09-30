# -*- coding: utf-8 -*-
 
N, L, T = map(int, input().split())
 
ants = []
for i in range(N):
    x, w = map(int, input().split())
    ants.append((x, w))
 
# After T
ants2 = []
for ant in ants:
    ants2.append((ant[0] + T * (3 - 2 * ant[1])) % L)
 
st = 0
for i in range(N):
    if ants2.count(ants2[i]) == 1:
        break
    st += 1
 
# Number of collision for Ants[st]
cl = 0
for i in range(N):
    if ants[i][1] == ants[st][1]:
        continue  # same direction
    else:
        if ants[st][1] == 1:
            if ants[i][0] > ants[st][0]:
                fc = (ants[i][0] - ants[st][0]) / 2
            else:
                fc = ((L - ants[st][0]) + ants[i][0]) / 2
            cl += (2 * (T - fc)) // L + 1
        else:
            if ants[i][0] > ants[st][0]:
                fc = ((L - ants[i][0]) + ants[st][0]) / 2
            else:
                fc = (ants[st][0] - ants[i][0]) / 2
            cl -= (2 * (T - fc)) // L + 1
 
stant = ants2[st]
ants2.sort()
idx = ants2.index(stant) - int(cl) - st
 
for i in range(N):
    print(ants2[(i + idx) % N])