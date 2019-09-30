R,C,K = map(int,input().split())
N = int(input())
R_ary = [0]*R
C_ary = [0]*C
ary = []

for i in range(N):
    r,c = list(map(int,input().split()))
    R_ary[r-1] += 1
    C_ary[c-1] += 1
    ary.append([r-1,c-1])

rlist = [0] *(K + 1)
clist = [0] *(K + 1)

for i in R_ary:
    if i <= K:
        rlist[i] += 1
for i in C_ary:
    if i <= K:
        clist[i] += 1
        
cnt = 0

for i in range(K+1):
    cnt += rlist[i] * clist[K-i]

for ar in ary:
    if R_ary[ar[0]] + C_ary[ar[1]] == K:
        cnt -= 1
    elif R_ary[ar[0]] + C_ary[ar[1]] == K+1:
        cnt += 1
        
        
    

print(cnt)