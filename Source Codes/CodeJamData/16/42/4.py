
input = raw_input
import itertools

def product(l):
    x = 1.
    for u in l: x *= u
    return x

def solve(k, l):
    maxi = 0
    for c in itertools.combinations(list(range(len(l))), k):
        s = 0
        for z in itertools.combinations(c, k // 2):
            s += product(l[i] for i in z) * product(1. - l[i] for i in c if i not in z)
        if s > maxi:
            maxi = s
    return maxi

t = int(input())
for i in range(t):
    print "Case #%s:" % (i + 1),
    n, k = map(int, input().split())
    l = map(float, input().split())
    print solve(k, l)
