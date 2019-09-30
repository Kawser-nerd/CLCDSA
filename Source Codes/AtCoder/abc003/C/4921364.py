N, K = [int(i) for i in input().split()]
RList = sorted([int(i) for i in input().split()], reverse=True)[:K]

ans = 0
for i, r in enumerate(RList[::-1]):
    ans = (r + ans) / 2

print(ans)