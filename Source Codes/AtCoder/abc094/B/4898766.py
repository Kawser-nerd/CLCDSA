N, M, X = map(int, input().split())

l = [0]*(N+1)
A = list(map(int, input().split()))
for a in A:
    l[a] = 1

print(min(sum(l[:X]), sum(l[X:])))