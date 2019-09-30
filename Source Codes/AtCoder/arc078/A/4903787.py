N = int(input())
As = list(map(int, input().split()))

for i in range(1, len(As)):
    As[i] += As[i-1]

res = 2*10**14
for i in range(len(As)-1):
    res = min(res, abs(2 * As[i] - As[-1]))
print(res)