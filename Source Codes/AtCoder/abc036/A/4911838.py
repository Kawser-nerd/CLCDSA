from math import ceil


def tea(A: int, B: int)->int:
    return ceil(B/A)


if __name__ == "__main__":
    A, B = map(int, input().split())
    ans = tea(A, B)
    print(ans)