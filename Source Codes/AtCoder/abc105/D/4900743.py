N, M = map(int, input().split())
A = [int(i) for i in input().split()]

sum_A = [0] * (N+1)

d = dict()
d[0] = 1
for i in range(N):
    sum_A[i+1] = sum_A[i] + A[i]
    sum_A[i+1] = sum_A[i+1] % M
    if sum_A[i+1] in d:
        d[sum_A[i+1]] += 1
    else:
        d[sum_A[i+1]] = 1

answer = 0


for i in d.keys():
    answer += d[i] * (d[i]-1) // 2


print(answer)