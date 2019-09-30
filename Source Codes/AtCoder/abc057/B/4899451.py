n, m = map(int, input().split())
a = []
b = []
for _ in range(n):
    a1, b1 = map(int, input().split())
    a.append([a1, b1])
for _ in range(m):
    c, d = map(int, input().split())
    b.append([c, d])
for a_ in a:
    e = []
    for b_ in b:
        ans = abs(a_[0] - b_[0]) + abs(a_[1] - b_[1])
        e.append(ans)
    print(e.index(min(e))+1)