def max_mul(A: int)->int:
    return (A * A) // 4


if __name__ == "__main__":
    A = int(input())
    ans = max_mul(A)
    print(ans)