import collections
import sys

m = {"o" : "0", 
     "i" : "1", 
     "e" : "3", 
     "a" : "4", 
     "s" : "5", 
     "t" : "7", 
     "b" : "8", 
     "g" : "9"}
mr = {y: x for x, y in m.items()}

bak = sys.stdin
sys.stdin = open('input.txt')

for kase in range(int(input())):
    din = collections.defaultdict(lambda: 0)
    dout = collections.defaultdict(lambda: 0)
    g = set()
    a = set()
    n = int(input())
    assert n == 2
    s = input()
    ans = 0
    for i in range(len(s)-1):
        for p in range(int(2)):
            for q in range(int(2)):
                c1, c2 = s[i: i+2]
                if p == 1 and c1 in m: c1 = m[c1]
                if q == 1 and c2 in m: c2 = m[c2]
                if c1+c2 not in g:
                    g.add(c1+c2)
                    dout[c1] += 1
                    din[c2] += 1
                    a.add(c1)
                    a.add(c2)
                    ans += 1
    tot = 0
    for i in a:
        tot += abs(din[i] - dout[i])
    if tot == 0:
        ans += 1
    else:
        ans += tot//2
    print("Case #{}: {}".format(kase+1, int(ans)))

#sys.stdin = bak
#input()
