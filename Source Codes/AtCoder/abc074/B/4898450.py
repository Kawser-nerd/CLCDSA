N = int(input())
K = int(input())
X = list(map(int, input().split()))
ans = 0
for x in X:
    ans += x * 2 if x < K - x else (K - x) * 2
print(ans)