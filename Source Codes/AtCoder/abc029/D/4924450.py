def one(N: int) -> int:
    res = 0
    M = 10

    while N // M:
        R = N % M
        res += (N - R) // 10

        if R * 10 >= M:
            if R * 10 < 2 * M:
                res += R - M // 10 + 1
            else:
                res += M // 10
        else:
            res += 0

        M *= 10

    R = N % M
    if R * 10 >= M:
        if R * 10 < 2 * M:
            return res + R - M // 10 + 1
        else:
            return res + M // 10

    return res


if __name__ == "__main__":
    N = int(input())
    ans = one(N)
    print(ans)