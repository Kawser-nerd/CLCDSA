N=int(input())
Tn=list(map(int,input().split()))
M=int(input())
PX=[list(map(int, input().split())) for _ in range(M)]

t = sum(Tn)
for p, x in PX:
    print(t - (Tn[p-1]-x))