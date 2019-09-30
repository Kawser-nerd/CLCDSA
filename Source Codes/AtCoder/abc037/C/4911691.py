def summary(N: int, K: int, A: list)->int:
    s = sum(A[:K])
    ans = s

    for offset in range(N-K):
        s = s - A[offset] + A[offset+K]
        ans += s

    return ans


if __name__ == "__main__":
    N, K = map(int, input().split())
    A = [int(s) for s in input().split()]
    ans = summary(N, K, A)
    print(ans)