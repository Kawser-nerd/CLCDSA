N, K = map(int, input().split())
a = list(map(int, input().split()))
sub_sum = 0
all_sum = 0
for i in range(K):
    sub_sum += a[i]
all_sum += sub_sum
for i in range(K, N):
    sub_sum -= a[i-K]
    sub_sum += a[i]
    all_sum += sub_sum
print(all_sum)