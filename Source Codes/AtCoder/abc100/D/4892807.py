from operator import mul
import sys
stdin = sys.stdin
 
sys.setrecursionlimit(10**5) 
 
def li(): return map(int, stdin.readline().split())

N, M = tuple(li())
Cs = []
for i in range(N):
    n = tuple(li())
    Cs.append(n)
# state:  x, y, z, point
state = [0, 0, 0, 0]
maximum = 0
trans = []
for per in range(8):
    ops = [1 if (per&4)>>2 else -1, 1 if (per&2)>>1 else -1, 1 if per&1 else -1]
    trans.clear()
    for i in range(N):
        trans.append(list(map(mul, Cs[i], ops)))
    trans.sort(key=lambda x: -sum(x))
    maximum = max(maximum, sum(sum(t) for t in trans[:M]))
        

print(maximum)