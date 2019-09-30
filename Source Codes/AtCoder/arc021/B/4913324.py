#import math
L = int(input())
B = [int(input()) for _ in range(L)]
#B_max = max(B)
#B_max_log2_int_plus1 = int(math.log2(B_max)) + 1
z = B[0]
for y in B[1:]:
    z = z^y
if z == 0:
    g = 0
    A = [0]
    for c in B:
        g = g^c
        A.append(g)
    for t in A[:-1]:
        print(t)
else:
    print(-1)