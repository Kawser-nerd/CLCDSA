N = int(input())
K = int(input())
X = list(map(int, input().split()))

ans = 0
for x in X:
    ans += 2*min(x, abs(K-x))

print(ans)