def tak_and_hotels(N: int, K: int, X: int, Y: int) -> int:
    return min(N, K) * X + max(0, N - K) * Y


if __name__ == "__main__":
    N = int(input())
    K = int(input())
    X = int(input())
    Y = int(input())
    ans = tak_and_hotels(N, K, X, Y)
    print(ans)