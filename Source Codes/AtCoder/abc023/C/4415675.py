def main():
    rows, cols, k = map(int, input().split())
    n = int(input())
    candies = []
    for _ in range(n):
        r, c = map(int, input().split())
        candies.append((r - 1, c - 1))
    
    print(solve(rows, cols, k, candies))

def solve(rows, cols, k, candies):
    row_c = count((c[0] for c in candies), rows)
    col_c = count((c[1] for c in candies), cols)
    row_cc = count(row_c.values(), cols + 1)
    col_cc = count(col_c.values(), rows + 1)

    cnt = 0
    for i in range(k + 1):
        cnt += row_cc.get(i, 0) * col_cc.get(k - i, 0)
    
    for r, c in candies:
        x = row_c[r] + col_c[c]
        if x == k:
            cnt -= 1
        elif x == k + 1:
            cnt += 1

    return cnt

def count(items, m):
    cnt = dict((i, 0) for i in range(m))
    for v in items:
        cnt[v] = cnt.get(v, 0) + 1
    return cnt

main()