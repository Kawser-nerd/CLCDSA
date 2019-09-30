def atcodeer_and_paint_cans(a: int, b: int, c: int) -> int:
    return len(set([a, b, c]))


if __name__ == "__main__":
    a, b, c = map(int, input().split())
    ans = atcodeer_and_paint_cans(a, b, c)
    print(ans)