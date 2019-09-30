n,A,B = map(int,input().split())
l = [int(input()) for i in range(n)]
dif = max(l) - min(l)
if dif == 0:
    print(-1)
else:
    P = B / dif
    l = [l[i]*P for i in range(n) ]
    ave = sum(l)/n
    Q = A - ave
    print(P,Q)