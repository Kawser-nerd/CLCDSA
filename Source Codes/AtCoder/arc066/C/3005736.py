input()
sm = de = 0
ans = 10 ** 15
for s in (input() + "-0").split('-'):
    a = list(map(int, s.split('+')))
    if sm:
        ans = min(ans, sum(a) + de)
        de += a[0]
    sm += sum(a)
print(sm - 2 * ans)