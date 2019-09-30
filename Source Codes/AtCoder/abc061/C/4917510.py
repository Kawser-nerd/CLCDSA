N, K = list(map(int, input().split()))
num = [0] * (10 ** 5)
for i in range(N):
    a, b = list(map(int, input().split()))
    num[a - 1] += b

cnt = 0
for i in range(len(num)):
    cnt += num[i]
    if cnt >= K:
        print(i + 1)
        exit()