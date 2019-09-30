import sys

input = sys.stdin.readline

n = int(input())
lis = [list(map(int, input().rstrip().split('-'))) for _ in range(n)]

lis.sort()

for i in range(n):
    lis[i][0] = lis[i][0] - lis[i][0] % 5

    if (lis[i][1] % 5 != 0):
        lis[i][1] = lis[i][1] - lis[i][1] % 5 + 5

    tmp2 = lis[i][1] / 100

    if (tmp2 - int(tmp2) > 0.59999):
        lis[i][1] = (int(tmp2) + 1) * 100
    if (lis[i][1] >= 2360):
        lis[i][1] = 2400

ans1 = [lis[0]]
aaaa = ans1[0]

for i in range(1, n):
    if (aaaa[1] < lis[i][0]):
        ans1.append(lis[i])
        aaaa = ans1[-1]
    else:
        if (aaaa[1] < lis[i][1]):
            ans1[-1][1] = lis[i][1]


for i in range(len(ans1)):
    start = str(ans1[i][0])
    end = str(ans1[i][1])
    print(start.zfill(4)+'-'+end.zfill(4))