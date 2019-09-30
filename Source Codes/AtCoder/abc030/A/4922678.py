def win_rate(A: int, B: int, C: int, D: int) -> str:
    if B * C < A * D:
        return 'AOKI'
    if B * C > A * D:
        return 'TAKAHASHI'
    return 'DRAW'


if __name__ == "__main__":
    A, B, C, D = map(int, input().split())
    ans = win_rate(A, B, C, D)
    print(ans)