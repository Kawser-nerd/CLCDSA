N,K = map(int,input().split())
wp = [list(map(int,input().split())) for i in range(N)]

NGline = 100
OKline = 0

def bisection(sup,inf):
    mid = (sup+inf)/2
    A = []
    for i in range(N):
        A.append(wp[i][0]*(wp[i][1]-mid)/100)
    A.sort(reverse = True)
    S = sum(A[:K])

    if S > 0:
        inf = mid
    else:
        sup = mid

    return sup,inf

for i in range(1000):
    NGline,OKline = bisection(NGline,OKline)

print((NGline+OKline)/2)