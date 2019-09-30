def pair(N: int)->int:
    if N % 2 == 0:
        return N - 1
    return N + 1


if __name__ == "__main__":
    N = int(input())
    ans = pair(N)
    print(ans)