B = input().split(" ")
N = int(input())
A = [input() for _ in range(N)]

def f(s):
    # print([B.index(c) for c in s])
    return int("".join(str(B.index(c)) for c in s))

[print(a) for a in sorted(A, key=f)]