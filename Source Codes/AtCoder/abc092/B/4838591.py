N=int(input())
D,X,=map(int,input().split())
An=[int(input()) for _ in range(N)]
c = 0
for n in range(N):
    i = 0
    while True:
        d = i*An[n] + 1
        if d > D:
            break
        c += 1
        i += 1
print(c+X)