N = int(input())
A = list(map(int, input().split()))
As = sorted(A)
cumax = [0]*N
ma = 0
for i, a in enumerate(A):
    cumax[i] = max(cumax[i-1], a)

ias = 0
pma = 0
ofs = 0
for i, a in enumerate(cumax):
    if a == pma:
        print(0)
        continue
    s = 0
    while ias < N and As[ias] <= a:
        s += As[ias] - ofs
        ias += 1
    s += (N-ias)*(a-ofs)
    pma = a
    ofs = a
    print(s)