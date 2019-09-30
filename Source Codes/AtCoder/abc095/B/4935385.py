N, X = map(int, input().split())
m = [int(input()) for i in range(N)]
tmp = (X - sum(m)) // min(m)
print(tmp + N)