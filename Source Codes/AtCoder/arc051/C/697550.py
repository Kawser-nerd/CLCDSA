N,A,B = map(int,input().split())
a = list(map(int,input().split()))
a.sort()
mo = 10**9 + 7
loop = 0

if A == 1:
    for i in range(N):
        print(a[i] % mo)
    exit()

a_max = a[-1]
while B > 0:
    if a[0] * A >= a_max:
        loop = B//N
        B %= N
        break

    a[0] *= A
    B -= 1
    a.sort()

i = 0
while B > 0:
    a[i] *= A
    B -= 1
    i += 1

for i in range(N):
    a[i] *= pow(A, loop, mo)

a.sort()

for i in range(N):
    a[i] %= mo
    print(a[i])