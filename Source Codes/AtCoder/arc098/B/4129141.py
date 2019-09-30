N = int(input())
A = list(map(int,input().split()))

ans = 0
r = 0
tmp = 0
for l in range(N):
    while r < N and (tmp&A[r]) == 0:
        tmp += A[r]
        r += 1
    tmp -= A[l]
    ans += r - l
print(ans)