N, M = map(int,input().split())
X = list(map(int,input().split()))

X.sort()
if N>=M:
    print(0)
else:
    tmp=[]
    for i in range(M-1):
        tmp.append(X[i+1] - X[i])
    tmp.sort(reverse = True)
    interval = 0
    for i in range(N-1):
        if i+1 == M-1:
            break
        interval += tmp[i]
    print(sum(tmp) - interval)