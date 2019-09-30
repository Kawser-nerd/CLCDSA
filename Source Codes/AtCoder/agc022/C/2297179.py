def solve(a, b):
    if a == b:
        yield []
    if a > b:
        for i in range(1, a+1):
            for x in solve(a % i, b):
                yield [i] + x

def subseq(a, b):
    if len(b) == 0: return True
    x = 0
    for t in a:
        if t == b[x]:
            x += 1
            if x == len(b):
                return True
    return False

n = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

R = []

for i in range(n):
    R.append(list(solve(A[i], B[i])))
    if len(R[-1]) == 0:
        print(-1)
        exit(0)

L = []
answer = 0

for i in range(50, 0, -1):
    T = L + list(range(i - 1, 0, -1))

    ok = True

    for j in range(n):
        cur = False

        for seq in R[j]:
            if subseq(T, seq):
                cur = True
                break

        if not cur:
            ok = False
            break

    if not ok:
        L.append(i)
        answer += 2**i

print(answer)