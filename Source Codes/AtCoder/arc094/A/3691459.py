def inpl(): return [int(i) for i in input().split()]
A, B, C = inpl()
A, B, C = max(A, B, C), A+B+C -max(A, B, C) -min(A, B, C), min(A, B, C)
if (B-C)%2 == 0:
    print((2*A -B -C)//2)
else:
    print((2*A -B -C +3)//2)