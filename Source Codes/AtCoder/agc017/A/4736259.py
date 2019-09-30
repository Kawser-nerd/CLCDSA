from math import factorial as fact

N, P = map(int, input().split())
A = [int(_) for _ in input().split()]
oddcnt = 0
evencnt = 0
for i in A:
    if i % 2 == 1:
        oddcnt += 1
    else:
        evencnt += 1

even = 2**evencnt
odd = 0
if P == 0:
    for i in range(0, oddcnt+1, 2):
        odd += fact(oddcnt) // (fact(i)*fact(oddcnt-i))
else:
     for i in range(1, oddcnt+1, 2):
        odd += fact(oddcnt) // (fact(i)*fact(oddcnt-i))

print(even*odd)