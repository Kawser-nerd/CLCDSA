from copy import deepcopy
N = int(input())
A = [int(input()) for n in range(N)]
Aorder = deepcopy(A)
Aorder.sort()
odd, even = set(), set()
for i in range(N):
    if i % 2 == 0:
        even |= {Aorder[i]}
    else:
        odd |= {Aorder[i]}

missmatch = 0
for i in range(N):
    if i % 2 == 0:
        if A[i] in odd: missmatch += 1
    else:
        if A[i] in even: missmatch += 1
print(missmatch//2)