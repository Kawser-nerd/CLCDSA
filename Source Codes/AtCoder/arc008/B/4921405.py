N, M = map(int, input().split())
name = input()
kit = input()
c1 = 0
c2 = 0
m = 0
for s in name:
    c1 = name.count(s)
    c2 = kit.count(s)
    if c2 != 0:
        m = max(m, -(-c1 // c2))
    else:
        print(-1)
        exit()
print(m)