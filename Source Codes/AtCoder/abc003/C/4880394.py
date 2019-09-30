N, K = map(int, input().split())
R = list(map(int, input().split()))
R.sort(reverse=True)
rate = 0
for r in R[0:K][::-1]:
    rate = (rate + r) / 2
print(rate)