N,K = map(int,input().split())
t = [int(input()) for _ in range(N)]
for i in range(N-2):
    if sum(t[i:i+3]) < K:
        print(i+3)
        break
else:
    print(-1)