N, X = map(int, input().split())

m = [int(input()) for i in range(N)]

X -= sum(m)

ans = (X // min(m)) + N

print(ans)