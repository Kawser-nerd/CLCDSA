def main():
    N = int(input())
    T, X, Y = 0, 0, 0
    for _ in range(N):
        t, x, y = list(map(int, input().split()))
        dx = abs(x - X)
        dy = abs(y - Y)
        dt = t - T
        if (dx + dy) % 2 != dt % 2:
            print('No')
            return
        if dx + dy > dt:
            print('No')
            return
        T, X, Y = t, x, y
    print('Yes')

main()