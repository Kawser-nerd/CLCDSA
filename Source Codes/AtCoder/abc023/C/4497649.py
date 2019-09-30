# encoding: utf-8
R, C, K = map(int, input().split())
N = int(input())
rc = [list(map(int, input().split())) for i in range(N)]

rcnt = [0] * R
ccnt = [0] * C
for ri, ci in rc:
    rcnt[ri - 1] += 1
    ccnt[ci - 1] += 1

rhist = [0] * (C + 1)
chist = [0] * (R + 1)
for rcnti in rcnt: rhist[rcnti] += 1
for ccnti in ccnt: chist[ccnti] += 1

ans = 0
for i in range(K + 1):
    if i > C or (K - i) > R: continue
    ans += (rhist[i] * chist[K - i])
    # print("# pair", (i, K - i), ans)
    
for ri, ci in rc:
    if rcnt[ri - 1] + ccnt[ci - 1] == K + 1:
        ans += 1
        # print("# add", (ri, ci), ans)
    elif rcnt[ri - 1] + ccnt[ci - 1] == K:
        ans -= 1
        # print("# del", (ri, ci), ans)

print(ans)