def solve(n, tbl):
    ans = 0
    for i, row_i in enumerate(tbl):
        for j in range(i + 1, n):
            row_j = tbl[j]
            ij = row_i[j]
            mind = min((ik + kj for ik, kj in zip(row_i, row_j) if ik and kj), default=float('inf'))
            if ij > mind:
                return -1
            if ij < mind:
                ans += ij
    return ans


n = int(input())
tbl = [list(map(int, input().split())) for _ in range(n)]
print(solve(n, tbl))