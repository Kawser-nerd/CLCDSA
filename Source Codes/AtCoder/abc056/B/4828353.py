def narrow_rectangles_easy(W: int, a: int, b: int) -> int:
    if a + W < b:
        return b - (a + W)
    if b + W < a:
        return a - (b + W)
    return 0


if __name__ == "__main__":
    W, a, b = map(int, input().split())
    ans = narrow_rectangles_easy(W, a, b)
    print(ans)