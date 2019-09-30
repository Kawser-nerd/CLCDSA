N, K = map(int, input().split())
dK = 2*K

MeetDemand =[[0 for y in range(dK+1)] for x in range(K+1)]
for i in range(N):
    x, y, c =input().split()
    x = int(x) % dK
    y = (int(y)+K if c=="W" else int(y)) % dK
    if K <= x:
        if 0 <= y < K:
            x -= K
            y += K
        else:
            x %= K
            y %= K
    if 0 <= y < K:
        MeetDemand[0][0] += 1
        MeetDemand[x+1][y+1] += 2
        MeetDemand[0][y+1] -= 1
        MeetDemand[x+1][0] -= 1
        MeetDemand[0][y+K+1] += 1
        MeetDemand[x+1][y+K+1] -= 2
    else:
        MeetDemand[0][y-K+1] += 1
        MeetDemand[x+1][y-K+1] -= 2
        MeetDemand[x+1][0] += 1
        MeetDemand[0][y+1] -= 1
        MeetDemand[x+1][y+1] += 2

for x in range(K):
    for y in range(1, dK):
        MeetDemand[x][y] += MeetDemand[x][y-1]
for y in range(dK):
    for x in range(1, K):
        MeetDemand[x][y] += MeetDemand[x-1][y]

Ans = max(MeetDemand[0][:dK])
for i in range(1, K):
    Ans = max(Ans, max(MeetDemand[i][:dK]))
print(Ans)