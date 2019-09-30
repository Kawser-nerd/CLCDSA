n = int(input())
ab = [[int(_) for _ in input().split()] for _ in range(n)]
ans = [0] * 1000002
               
for i in ab:
    ans[i[0]] += 1
    ans[i[1]+1] -= 1

tmp = 0
Cnum = [0]*(1000001)
for i in range(1000001):
    tmp += ans[i]
    Cnum[i] = tmp

print(max(Cnum))