def takahashi_rect(A: int, B: int, C: int)->int:
    return 2 * (A*B + B*C + C*A)


if __name__ == "__main__":
    A, B, C = map(int, input().split())
    ans = takahashi_rect(A, B, C)
    print(ans)