def solve(N, K, XYs):
    ans = 10 ** 19 + 1

    XYs.sort(key=lambda x: x[0])
    for i in range(N):
        for j in range(i+K-1, N):
            narrowedXY = XYs[i:j+1]
            narrowedXY.sort(key=lambda x: x[1])
            for y1 in range(len(narrowedXY)):
                for y2 in range(y1+K, len(narrowedXY)+1):
                    min_x = XYs[i][0]
                    max_x = XYs[j][0]
                    ys = [xy[1] for xy in narrowedXY[y1:y2]]
                    max_y = max(ys)
                    min_y = min(ys)
                    ans = min(ans, abs(max_x - min_x) * abs(max_y - min_y))

    return ans

if __name__ == "__main__":
    N, K = tuple(map(int, input().split(" ")))
    XYs = [tuple(map(int, input().split(" "))) for _ in range(N)]
    print(solve(N, K, XYs))