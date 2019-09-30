def zoo(A: int, B: int, C: int, K: int, S: int, T: int)->int:
    total = A*S + B*T
    if S + T >= K:
        total -= C * (S+T)
    return total


if __name__ == "__main__":
    A, B, C, K = map(int, input().split())
    S, T = map(int, input().split())
    ans = zoo(A, B, C, K, S, T)
    print(ans)