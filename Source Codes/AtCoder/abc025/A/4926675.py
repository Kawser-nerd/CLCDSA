def string25(S: str, N: int) -> str:
    sortedS = sorted(S)
    count = 1
    for c1 in sortedS:
        for c2 in sortedS:
            if count == N:
                return c1 + c2
            count += 1
    return "hoge"


if __name__ == "__main__":
    S = input()
    N = int(input())
    ans = string25(S, N)
    print(ans)