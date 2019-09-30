D = [int(i) for i in input().split()]
J = [int(i) for i in input().split()]

ans = 0
for d, j in zip(D, J):
    ans += max(d, j)

print(ans)