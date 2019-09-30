N = int(input())
A = list(map(int,input().split()))
suma = sum(A)
unit = N*(N+1)//2
if suma % unit:
    print('NO')
    exit()
ope = suma // unit

d = A[0]-A[-1]
for a,b in zip(A,A[1:]):
    if (b-a)%N != d%N:
        print('NO')
        exit()

AA = A + [A[0]]
k = 0
for a,b in zip(AA,AA[1:]):
    if b-a > ope:
        print('NO')
        exit()
    k += (ope - (b-a)) // N

print('YES' if k==ope else 'NO')