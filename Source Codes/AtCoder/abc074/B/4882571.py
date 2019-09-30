N = int(input())
K = int(input())
X = list(map(int, input().split()))

sum_len = 0
for i in range(len(X)):
    if X[i] < abs(K-X[i]):
        sum_len += X[i] * 2
    else:
        sum_len += abs(K-X[i]) * 2

print(sum_len)