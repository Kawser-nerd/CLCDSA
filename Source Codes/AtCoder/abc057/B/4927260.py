import sys

def main():
    input = sys.stdin.readline
    N, M = map(int, input().split())

    init = []
    for _ in range(N):
        a, b = map(int, input().split())
        init.append((a, b))

    check = []
    for _ in range(M):
        c, d = map(int, input().split())
        check.append((c, d))

    for i in init:
        pos = 0
        dist = 10**9
        x0, y0 = i[0], i[1]
        for j in range(M):
            x1, y1 = check[j][0], check[j][1]
            if abs(x0 - x1) + abs(y0 - y1) < dist:
                pos = j + 1
                dist = abs(x0 - x1) + abs(y0 - y1)

        print(pos)


if __name__ == '__main__':
    main()