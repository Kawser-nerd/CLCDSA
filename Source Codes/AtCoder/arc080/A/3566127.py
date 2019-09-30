def inpl(): return [int(i) for i in input().split()]

N = int(input())
a = inpl()
A4 = A2 = A1 = 0
for i in range(N):
    if a[i] % 4 == 0:
        A4 += 1
    elif a[i] % 2 == 0:
        A2 = 1
    else:
        A1 += 1

if (A4+A2+A1)//2 <= A4:
    print('Yes')
else:
    print('No')