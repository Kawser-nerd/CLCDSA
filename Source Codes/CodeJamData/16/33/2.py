t = int(input())

for i in range(t):
    print("Case #" + str(i + 1) + ":", end = " ")
    j, p, s, k = map(int, input().split())
    print(j * p * min(s, k))
    u = min(s, k)
    for a in range(j):
        for b in range(p):
            for r in range(u):
                c = (a + b + r) % s
                print(a + 1, b + 1, c + 1)
