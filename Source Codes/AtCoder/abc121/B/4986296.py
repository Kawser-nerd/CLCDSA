N, M, C = map(int, input().split())

B = list(map(int, input().split()))

cnt = 0

for i in range(N):
    A = list(map(int, input().split()))
    sum_value = [x*y for x, y in zip(A, B)]
    if (sum(sum_value)+C)>0:
        cnt += 1

print(cnt)