import sys
input = sys.stdin.readline

N = int(input())
a = [int(input()) for _ in range(N)]
anslist = [0]*N

for i, j in enumerate(a):
    anslist[i] = [i, j, 0]

anslist = sorted(anslist, key=lambda x:x[1])
tmp = anslist[0][1]
cnt = 0

for i in range(1, N):
    if anslist[i][1] == tmp:
        anslist[i][2] = cnt
    else:
        tmp = anslist[i][1]
        cnt += 1
        anslist[i][2] = cnt

anslist = sorted(anslist, key=lambda x:x[0])
for i in anslist:
    print(i[2])