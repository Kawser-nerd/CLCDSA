import sys
import random
from itertools import permutations


def flip(k):
    if k < 10:
        return k
    
    # k = 10a+b
    b = k%10
    a = int(k/10)
    digits = len(str(a))
    return b*(10**digits)+flip(a)

solution = []

for n in xrange(10):
    solution.append(n)

def sol(k):
    if len(solution) <=k:
        best = sol(k-1)
        a = flip(k)
        if a < k and flip(a) == k:
            best = min(best, sol(a))
        solution.append(best+1)
    
    return solution[k]


def sol2(n):
    if n < 100:
        return sol(n)
    
    digits = len(str(n))
    m = int((digits+1)/2)
    
    target = n - (n % (10**m)) + 1
    
    if n < target:
        n1 = target-2
        digits = len(str(n1))
        m = int((digits+1)/2)
        target = n1 - (n1 % (10**m)) + 1
    
    if target == 10**(digits-1)+1:
        n1 = target-2
        digits = len(str(n1))
        m = int((digits+1)/2)
        target = n1 - (n1 % (10**m)) + 1
    
    return n-target + sol2(flip(target)) + 1


def solve():
    n = int(sys.stdin.readline())
    
    print sol2(n)
    
t = int(sys.stdin.readline())
for i in xrange(t):
    print "Case #%d:" % (i+1),
    solve()

