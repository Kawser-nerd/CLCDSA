def axis_parallel_rectangle(N: int, K: int, xy: list)->int:
    # 1. ????
    sorted_x = sorted(v[0] for v in xy)
    sorted_y = sorted(v[1] for v in xy)

    XY = [(sorted_x.index(v[0]), sorted_y.index(v[1])) for v in xy]
    # 2. ????????????????????????
    S = [[0] * (N+1) for _ in range(N+1)]
    for x, y in XY:
        S[x+1][y+1] = 1

    for x in range(N+1):
        for y in range(N):
            S[x][y+1] += S[x][y]

    for y in range(N+1):
        for x in range(N):
            S[x+1][y] += S[x][y]

    # 3. x ??????????
    min_area = float('inf')
    for x1 in range(N):
        for x2 in range(x1+1, N):
            for y1 in range(N):
                for y2 in range(y1+1, N):
                    count = S[x2+1][y2+1]-S[x2+1][y1]-S[x1][y2+1]+S[x1][y1]
                    if count < K:
                        continue
                    xmin, xmax = sorted_x[x1], sorted_x[x2]
                    ymin, ymax = sorted_y[y1], sorted_y[y2]
                    min_area = min(min_area, (xmax-xmin)*(ymax-ymin))
    # ??? O(N^3) = O(10^5) ??? ?
    return min_area


if __name__ == "__main__":
    N = 0
    N, K = map(int, input().split())
    xy = [tuple(map(int, input().split())) for _ in range(N)]
    ans = axis_parallel_rectangle(N, K, xy)
    print(ans)