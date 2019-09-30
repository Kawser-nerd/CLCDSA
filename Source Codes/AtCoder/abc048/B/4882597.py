def between_a_and_b(a: int, b: int, x: int) -> int:
    return b // x - (a-1) // x


if __name__ == "__main__":
    a, b, x = map(int, input().split())
    ans = between_a_and_b(a, b, x)
    print(ans)