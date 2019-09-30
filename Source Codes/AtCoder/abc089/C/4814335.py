import sys
input = sys.stdin.readline

N = int(input())
S = [input() for _ in range(N)]
MARCHcnt = [0]*5
ans = 0

for i in S:
    if i[0] == 'M':
        MARCHcnt[0] += 1
    elif i[0] == 'A':
        MARCHcnt[1] += 1
    elif i[0] == 'R':
        MARCHcnt[2] += 1
    elif i[0] == 'C':
        MARCHcnt[3] += 1
    elif i[0] == 'H':
        MARCHcnt[4] += 1

for i in range(3):
    for j in range(i+1, 4):
        for k in range(j+1, 5):
            ans += MARCHcnt[i]*MARCHcnt[j]*MARCHcnt[k]

print(ans)