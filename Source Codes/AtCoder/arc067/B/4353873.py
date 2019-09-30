N, A, B = map(int, input().split())
X = list(map(int, input().split()))
num = 0
pre = X[0]
for i in range(1, N):
    num += min((X[i] - pre) * A, B)
    pre = X[i]

print(num)