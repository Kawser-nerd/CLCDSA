def inpl(): return [int(i) for i in input().split()]
C, B, A = sorted(inpl())
if (B-C)%2 == 0:
    print((2*A -B -C)//2)
else:
    print((2*A -B -C +3)//2)