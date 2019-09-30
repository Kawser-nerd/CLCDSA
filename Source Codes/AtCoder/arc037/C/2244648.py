N, K = map(int, input().split())
*A, = map(int, input().split())
*B, = map(int, input().split())
A.sort(reverse=1); B.sort()

def check(mid):
    j = 0
    res = 0
    for a in A:
        while j < N and a * B[j] <= mid:
            j += 1
        res += j
    return K <= res

left = 0; right = 10**18+1
while left + 1 < right:
    mid = (left + right) // 2
    if check(mid):
        right = mid
    else:
        left = mid
print(right)