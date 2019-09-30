def main():
    n = int(input())
    city = []
    for i in range(n):
        x,y = map(int, input().split())
        city.append((x,y,i))
    edges = []
    # x
    city.sort()
    for i in range(n-1):
        dist = city[i+1][0] - city[i][0]
        edges.append((dist, city[i][2], city[i+1][2]))
    # y
    city.sort(key=lambda x:x[1])
    for i in range(n-1):
        dist = city[i+1][1] - city[i][1]
        edges.append((dist, city[i][2], city[i+1][2]))

    edges.sort()
    ans = 0

    uf = [-1]*n
    def root(x):
        if uf[x] < 0:
            return x
        uf[x] = root(uf[x])
        return uf[x]
    def unite(x,y):
        rx, ry = root(x), root(y)
        if rx == ry:
            return False
        if rx > ry:
            rx,ry = ry,rx
        uf[rx] += uf[ry]
        uf[ry] = rx
        return True

    for dist, from_, to in edges:
        if unite(from_, to):
            ans += dist
    print(ans)

if __name__ == '__main__':
    main()