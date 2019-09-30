def merge(N: int, cities: list)->str:
    max_people = 0
    city = 'atcoder'
    total = 0
    for c, p in cities:
        if max_people < p:
            max_people = p
            city = c
        total += p
    return city if max_people > total // 2 else 'atcoder'


if __name__ == "__main__":
    N = int(input())
    cities = []
    for _ in range(N):
        c, p = input().split()
        cities.append((c, int(p)))
    ans = merge(N, cities)
    print(ans)