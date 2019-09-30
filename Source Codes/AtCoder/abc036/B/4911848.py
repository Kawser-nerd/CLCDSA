def rotate(N: int, S: list)->list:
    res = ['' for _ in range(N)]
    for i in range(N):
        for j in range(N):
            res[i] += S[N-j-1][i]

    return res


if __name__ == "__main__":
    N = int(input())
    S = [input() for _ in range(N)]
    ans = rotate(N, S)
    print('\n'.join(ans))