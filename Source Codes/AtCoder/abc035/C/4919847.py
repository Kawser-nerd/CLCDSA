def othello(N: int, Q: int, queries: list)->str:
    s = [0] * N

    for l, r in queries:
        s[l-1] += 1

        if r < N:
            s[r] -= 1

    cum = [0] * N
    cum[0] = s[0]

    for i in range(1, N):
        cum[i] = cum[i-1] + s[i]

    return ''.join('0' if c % 2 == 0 else '1' for c in cum)


if __name__ == "__main__":
    Q = 0
    N, Q = map(int, input().split())
    queries = [tuple(int(s) for s in input().split()) for _ in range(Q)]
    ans = othello(N, Q, queries)
    print(ans)