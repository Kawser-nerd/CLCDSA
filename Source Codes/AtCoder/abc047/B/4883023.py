def snuke_coloring2(W: int, H: int, N: int, queries: list) -> int:
    # ????????????
    u, d, r, l = H, 0, W, 0

    for x, y, a in queries:
        if a == 1:
            l = max(l, x)
        elif a == 2:
            r = min(r, x)
        elif a == 3:
            d = max(d, y)
        else:  # a == 4
            u = min(u, y)

    return max(r - l, 0) * max(u - d, 0)


if __name__ == "__main__":
    N = 0
    W, H, N = map(int, input().split())
    queries = [tuple(int(s) for s in input().split()) for _ in range(N)]
    ans = snuke_coloring2(W, H, N, queries)
    print(ans)