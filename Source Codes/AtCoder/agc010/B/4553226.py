N = int(input())
A = list(map(int,input().split()))

def solve():
    q = N * (N + 1) // 2
    if sum(A) % q:
        return False
    times = sum(A) // q
    cnt = 0
    for i, j in zip(A, A[1:] + [A[0]]):
        dif = times + i - j
        if dif % N or dif < 0:
            return False
        cnt += dif // N
    return times == cnt

print('YES' if solve() else 'NO')