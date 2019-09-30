N = int(input())
ans = 0
zahyou = list(map(int, input().split()))
zahyou.sort(reverse=True)
for i in range(N-1):
    ans += zahyou[i] - zahyou[i + 1]
print(ans)