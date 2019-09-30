def inpl(): return [int(i) for i in input().split()]
import bisect
N = int(input())
A = sorted(inpl())
B = inpl()
C = sorted(inpl())
ans = 0
for b in B:
    ans += bisect.bisect_left(A,b)*(N-bisect.bisect_right(C,b))
print(ans)