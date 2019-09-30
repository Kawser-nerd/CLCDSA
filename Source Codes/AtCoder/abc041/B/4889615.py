def rectangular(A: int, B: int, C: int)->int:
    MOD = 10**9 + 7
    return (A*B*C) % MOD


if __name__ == "__main__":
    A, B, C = map(int, input().split())
    ans = rectangular(A, B, C)
    print(ans)