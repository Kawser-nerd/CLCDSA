n = int(input())
ans = [0 for i in range(1000002)]
lis = [0 for i in range(1000002)]
for i in range(n):
    a, b = map(int, input().split())
    ans[a] += 1
    ans[b + 1] -= 1
for i in range(1000001):
    lis[i + 1] += lis[i] + ans[i]
lis[0] = ans[0]
lis.sort()
print(lis[-1])