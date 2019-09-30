N,M = map(int,input().split())
backet = [0]*N
for i in range(M):
    a,b = map(int,input().split())
    backet[a-1] += 1
    backet[b-1] += 1
for i in range(N):
    print(backet[i])