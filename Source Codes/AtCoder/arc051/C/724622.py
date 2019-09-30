N, A, B = map(int, input().split())
As = [int(a) for a in input().split()]
As.sort()
M = int(1e9 + 7)

def advance(n):
    for i in range(n):
        As[0] *= A
        As.sort()


def solve():
    if A == 1:
        return
    cnt = 0
    for i in range(B):
        cnt += 1
        As[0] *= A
        As.sort()
        if cnt == B:
            return

        if As[0] * A >= As[-1]:
            break

    if B - cnt > 0:
        q = (B - cnt) // len(As)
        r = (B - cnt) % len(As)
        Aq = pow(A, q, M)
        for j in range(len(As)):
            As[j] *= Aq
        advance(r)


solve()
for a in As:
    print(a % M)