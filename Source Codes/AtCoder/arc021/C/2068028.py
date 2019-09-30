K = int(input())
N = int(input())
C = [list(map(int, input().split())) for i in range(N)]

def solve(mid):
    res = 0
    for a, d in C:
        if mid < a:
            continue
        res += 1 + (mid - a) // d
    return res

left = 0; right = 10**12
while left+1 < right:
    mid = (left + right) // 2
    if solve(mid) < K:
        left = mid
    else:
        right = mid
b = right
ans = su = 0
for a, d in C:
    if b < a:
        continue
    k = 1 + (b - a) // d
    su += k
    ans += a*k + k*(k-1)//2*d
print(ans - (su - K)*b)