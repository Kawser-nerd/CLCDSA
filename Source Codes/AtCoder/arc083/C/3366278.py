N = int(input())
P = [0] + list(map(int, input().split()))
X = list(map(int, input().split()))

V = [[0, {0: True}, 0, 0] for i in range(N)]  # ??????????????????????
for i in range(1, N):
    V[P[i]-1][0] += 1

from collections import deque
Open = deque()
for i, v in enumerate(V):
    if v[0]==0:
        Open.append(i)
#print(Open)
while len(Open)!=0:
    iv = Open.popleft()
    v = V[iv]
    if len(v[1]) == 0:
        print("IMPOSSIBLE")
        exit()
    v[3] = v[2] - max(v[1].keys())

    u = P[iv]-1
    if u==-1:
        print("POSSIBLE")
        #print(V)
        exit()
    V[u][0] -= 1
    if V[u][0] == 0:
        Open.append(u)
    V[u][2] += X[iv] + v[3]
    newdic = {}
    for key, val in V[u][1].items():
        if key+X[iv] <= X[u]:
            newdic[key+X[iv]] = True
        if key+v[3] <= X[u]:
            newdic[key+v[3]] = True
    V[u][1] = newdic

raise ValueError