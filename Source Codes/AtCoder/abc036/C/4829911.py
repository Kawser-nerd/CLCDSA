N = int(input())
an = [int(input()) for _ in range(N)]

d = {a: i for i, a in enumerate(sorted(set(an)))}

for a in an:
    print(d[a])