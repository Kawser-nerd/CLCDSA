T = int(input())
N = int(input())
A = list(map(int,input().split()))
M = int(input())
B = list(map(int,input().split()))
ans = 'yes'
i = 0
if N < M:
    ans = 'no'
for b in B:
    if ans == 'no':
        break
    for a in range(i,N):
        if b>=A[a]>=b-T:
            ans = 'yes'
            i += 1
            break
        else:
            ans = 'no'
            i += 1
print(ans)