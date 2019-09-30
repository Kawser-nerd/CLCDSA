def trapezoids(a: int, b: int, h: int) -> int:
    return (a + b) * h // 2


if __name__ == "__main__":
    a, b, h = [int(input()) for _ in range(3)]
    ans = trapezoids(a, b, h)
    print(ans)