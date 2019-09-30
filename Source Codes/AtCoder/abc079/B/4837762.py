N = int(input())

L0 = 2
L1 = 1

i = N
while i-1 > 0:
    Ln = L0 + L1
    i -= 1
    L0 = L1
    L1 = Ln

if N == 0:
    print(2)
elif N == 1:
    print(1)
else:
    print(Ln)