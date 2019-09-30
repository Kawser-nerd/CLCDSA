N, M = map(int, input().split())
X = sorted(list(map(int, input().split())))
if N>=M:
    print(0)
else:
    sa=sorted([X[i+1]-X[i] for i in range(M-1)])
    print(sum(sa[0:M-N]))