N, K = map(int, input().split())
t = [int(input()) for _ in range(N)]
flag = False

for i in range(2, N):
    time = t[i]+t[i-1]+t[i-2]
    if time < K:
        flag = True
        break

print(i+1 if flag else -1)