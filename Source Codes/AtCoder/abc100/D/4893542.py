n,m = map(int, input().split())
P = [tuple(map(int, input().split())) for i in range(n)]

ans = [0]
for a in [-1,1]:
    for b in [-1,1]:
        for c in [-1,1]:
            res = []
            for x, y, z in P:
                res.append(a*x+b*y+c*z)
            res.sort(reverse=True)
            ans.append(sum(res[:m]))

print(max(ans))