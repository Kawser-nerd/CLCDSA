#14:59
#????
#hash???
N, K = map(int, input().split())

l = [0] * (10 ** 5 + 1)
for i in range(N):
    a, b = map(int, input().split())
    l[a] += b
cnt = 0
for i in range(1, 10 ** 5 + 1):
    cnt += l[i]
    if cnt >= K:
        print(i)
        break