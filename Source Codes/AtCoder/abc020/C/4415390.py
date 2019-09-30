def find_min(x, si, sj, ti, tj, s):

    dist = [
        [float("inf")] * 10 for _ in range(10)
    ]
    dist[si][sj] = 0

    H = len(s)
    W = len(s[0])

    updated = True
    while updated:
        updated = False
        for i in range(H):
            for j in range(W):
                c = x if s[i][j] == "#" else 1
                for dx, dy in [(1, 0), (-1, 0), (0, -1), (0, 1)]:
                    ii = i + dx
                    jj = j + dy
                    # print(ii, jj)
                    if 0 <= ii < 10 and 0 <= jj < 10 and dist[i][j] > dist[ii][jj] + c:
                        dist[i][j] = dist[ii][jj] + c
                        updated = True
    # print(dist)
    return dist[ti][tj]


def main():
    H, W, T = map(int, input().split())

    s = []
    for i in range(H):
        l = input()
        s.append(l)

        if l.find("S") != -1:
            si = i
            sj = l.find("S")
        if l.find("G") != -1:
            ti = i
            tj = l.find("G")

    # print(s)

    lo = 1
    hi = 10**9
    while hi - lo > 1:
        mid = (lo+hi)//2
        if find_min(mid, si, sj, ti, tj, s) <= T:
            lo = mid
        else:
            hi = mid

    if find_min(hi, si, sj, ti, tj, s) <= T:
        print(hi)
    else:
        print(lo)


main()