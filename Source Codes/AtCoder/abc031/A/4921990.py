def game(A: int, D: int)->int:
    return max((A + 1) * D, A * (D + 1))


if __name__ == "__main__":
    A, D = map(int, input().split())
    ans = game(A, D)
    print(ans)