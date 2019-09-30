def rect_rect_rect_rect_rect(n: int)->int:
    h = 1
    min_d = float('inf')
    while h * h <= n:
        w = n // h
        min_d = min(abs(h - w) + (n - w * h), min_d)
        h += 1
    return min_d


if __name__ == "__main__":
    n = int(input())
    ans = rect_rect_rect_rect_rect(n)
    print(ans)