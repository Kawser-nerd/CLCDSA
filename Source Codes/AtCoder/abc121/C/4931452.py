from collections import namedtuple

Shop = namedtuple('Shop', ('a', 'b'))

def main():
    n, m = map(int, input().split())
    shops = []
    for _ in range(n):
        a, b = map(int, input().split())
        shops.append(Shop(a, b))
    
    print(solve(shops, m))

def solve(shops, m):
    cost = 0
    count = 0

    for shop in sorted(shops):
        if count + shop.b >= m:
            cost += shop.a * (m - count)
            return cost
        
        count += shop.b
        cost += shop.a * shop.b

main()