N,X = map(int,input().split())
m=[int(input()) for _ in range(N)]
print((X-sum(m))//min(m) + N)