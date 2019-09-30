import sys
from collections import defaultdict

def solve():
    S = input()
    prev2 = ""
    prev = S[0]
    for i,v in enumerate(S[1:]):
        if v == prev:
            print(i+1,i+2)
            return
        elif v == prev2:
            print(i,i+2)
            return
        prev2 = prev
        prev = v
    print(-1,-1)
            
solve()