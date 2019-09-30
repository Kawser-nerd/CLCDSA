def manage(L: int, H: int, N: int, A: list) -> list:
    ret = []
    for a in A:
        if a < L:
            ret.append(L - a)
        elif H < a:
            ret.append(-1)
        else:
            ret.append(0)
    return ret


if __name__ == "__main__":
    L, H = map(int, input().split())
    N = int(input())
    A = [int(input()) for _ in range(N)]
    ans = manage(L, H, N, A)
    for a in ans:
        print(a)