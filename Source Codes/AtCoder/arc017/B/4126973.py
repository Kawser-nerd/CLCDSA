def b_low_resolution(N, K, A):
    increasing_length = 1
    increasing_interval = []
    for j in range(1, N):
        if A[j] > A[j - 1]:
            increasing_length += 1
        else:
            increasing_interval.append(increasing_length)
            increasing_length = 1
    if increasing_length != 1:
        increasing_interval.append(increasing_length)

    ans = sum([max(i - K + 1, 0) for i in increasing_interval])
    return ans

N, K = [int(i) for i in input().split()]
A = [int(input()) for _ in [0] * N]
print(b_low_resolution(N, K, A))