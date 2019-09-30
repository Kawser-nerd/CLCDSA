def inpl(): return [int(i) for i in input().split()]
Q = int(input())
for _ in range(Q):
    A, B = sorted(inpl())
    c = int(-(-(A*B)**0.5//1)-1)
    ans = A-1 + max(0, c-A) + (-((-A*B)//(c+1))-1)
    print(ans)