N, M = map(int, input().split())
P = []; A = []; B = []
for i in range(M):
    p, a, b = input().split();
    P.append(int(p)); A.append(float(a)); B.append(float(b))

N = len(set(P))
N2 = 2**((N-1).bit_length())
AD = [1]*(N2*2+1)
BD = [0]*(N2*2+1)

def update(x, a, b):
    x += N2-1
    AD[x] = a; BD[x] = b
    while x > 0:
        x = (x - 1) // 2
        AD[x], BD[x] = AD[2*x+1]*AD[2*x+2], AD[2*x+2]*BD[2*x+1] + BD[2*x+2]

*P, = map({p: i for i, p in enumerate(sorted(set(P)))}.__getitem__, P)
ans = []
mi = ma = 1
for i in range(M):
    update(P[i], A[i], B[i])
    res = AD[0] + BD[0]
    mi = min(res, mi); ma = max(res, ma)
print("%.9f" % mi)
print("%.9f" % ma)