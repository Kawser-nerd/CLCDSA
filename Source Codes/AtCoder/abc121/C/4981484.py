import sys
input = sys.stdin.readline


if __name__ == '__main__':
    n, m = map(int, input().split())
    shops = []
    ans = 0
    for i in range(n):
        shops.append(list(map(int, input().split())))
    shops.sort(key=lambda x:x[0])

    for shop in shops:
        price = shop[0]
        available = shop[1]
        if m - available > 0:
            ans += price * available
            m -= available
        else:
            ans += price * m
            break

    print(ans)