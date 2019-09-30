N,X = [int(x) for x in input().split()]
m = [int(input()) for _ in range(N)]
print(int((X-sum(m))/min(m))+N)