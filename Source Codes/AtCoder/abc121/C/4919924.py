# -*- coding:utf-8 -*-

class Shop():
    def __init__(self, yen, num):
        self.yen = yen  # ???????
        self.num = num  # ????????


def solve():
    N, M = list(map(int, input().split(" ")))
    A, B = [], []
    shops = []
    for i in range(N):
        a, b = list(map(int, input().split(" ")))
        A.append(a)
        B.append(b)
        shops.append(Shop(a, b))
    
    shops = sorted(shops, key=lambda x: x.yen)

    ans = 0
    rest_count = M
    for i in range(N):
        if rest_count <= shops[i].num:
            ans += shops[i].yen * rest_count
            break
        ans += shops[i].yen * shops[i].num
        rest_count -= shops[i].num
    
    print(ans)


if __name__ == "__main__":
    solve()