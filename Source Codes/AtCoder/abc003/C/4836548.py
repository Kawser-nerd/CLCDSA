N, K = map(int, input().split())
R = list(map(int, input().split()))
R.sort(reverse=True)

rate = 0
for i in range(K):
  rate += R[i] / (2 ** (i + 1))

print(rate)