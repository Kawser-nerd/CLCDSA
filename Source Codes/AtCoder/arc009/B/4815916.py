B = [int(_) for _ in input().split()]
N = int(input())
A = [int(input()) for i in range(N)]

ct = dict((n, i)for i, n in enumerate(B))

def conv(n, B):
    result = sum(
        ct[(n // 10**i) % 10] * (10 ** i)
        for i in range(9)
    )
    return result

A.sort(key=lambda x:conv(x, B))

for a in A:
    print(a)