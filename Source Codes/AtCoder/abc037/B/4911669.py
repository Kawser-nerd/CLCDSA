def editorial(N: int, Q: int, queries: list)->list:
    a = [0] * N
    for l, r, t in queries:
        for i in range(l-1, r):
            a[i] = t
    return a


if __name__ == "__main__":
    Q = 0
    N, Q = map(int, input().split())
    queries = [tuple(int(s) for s in input().split()) for _ in range(Q)]
    ans = editorial(N, Q, queries)

    for a in ans:
        print(a)