def main():
    n, k = map(int, input().split())
    xycs = [input().split() for _ in range(n)]
    tbl = [[0 for _ in range(k*2+1)] for _ in range(k+1)]
    
    for sx, sy, c in xycs:
        rx, ry = map(int, (sx, sy))
        mx, my = (rx-1) % (2*k), (ry-1) % (2*k)
        dx, dy = (mx + is_black(c)*k + (my<k)*k) % (2*k), my%k

        if dx < k:
            tbl[0][0] += 1
            tbl[0][dx+1] -= 1
            tbl[dy+1][0] -= 1
            tbl[dy+1][dx+1] += 2

            tbl[0][dx+1+k] += 1
            tbl[dy+1][dx+1+k] -= 2
        else:
            dx = dx % k
            tbl[0][dx+1] += 1
            tbl[dy+1][0] += 1
            tbl[dy+1][dx+1] -= 2

            tbl[0][dx+1+k] -= 1
            tbl[dy+1][dx+1+k] += 2
    for i in range(k):
        for j in range(1, 2*k):
            tbl[i][j] += tbl[i][j-1]
    for i in range(1, k):
        for j in range(0, 2*k):
            tbl[i][j] += tbl[i-1][j]
    print(max(max(t for t in ts) for ts in tbl[:k][:2*k]))

def is_black(c):
    return 1 if c=='B' else 0

main()