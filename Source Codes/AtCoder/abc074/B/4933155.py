N = int(input())
K = int(input())
x = list(map(int, input().split()))
ans = []
for i in range(N):
    dx_a = abs(x[i] - 0)
    dx_b = abs(x[i] - K)
    ans.append(min(dx_a, dx_b) * 2)
print(sum(ans))