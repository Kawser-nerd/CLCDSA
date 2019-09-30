def sequence(N: int, K: int, S: list)->int:
    S += [K+1]

    if 0 in S:
        # 0 ????????????????
        return N

    maxlen = 0
    l, r = 0, 0
    t = 1
    while r < N:
        # ??????????
        while t * S[r] <= K:
            t *= S[r]
            r += 1
        maxlen = max(maxlen, r-l)

        # ?????
        if l < r:
            t //= S[l]
            l += 1
        else:
            l, r = l+1, r+1

    return maxlen


if __name__ == "__main__":
    N = 0
    N, K = map(int, input().split())
    S = [int(input()) for _ in range(N)]
    ans = sequence(N, K, S)
    print(ans)