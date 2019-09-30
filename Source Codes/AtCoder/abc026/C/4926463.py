def salary(N: int, B: list) -> int:
    tree = [[] for _ in range(N)]
    for i, b in enumerate(B):
        tree[b - 1].append(i + 1)

    def dfs(v: int) -> int:
        if not tree[v]:
            return 1

        max_s, min_s = 0, float('inf')
        for child in tree[v]:
            d = dfs(child)
            max_s = max(max_s, d)
            min_s = min(min_s, d)

        return max_s + min_s + 1

    return dfs(0)


if __name__ == "__main__":
    N = int(input())
    B = [int(input()) for _ in range(N-1)]
    ans = salary(N, B)
    print(ans)