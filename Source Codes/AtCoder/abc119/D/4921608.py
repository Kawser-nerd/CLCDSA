from bisect import bisect_left
import sys
input = sys.stdin.readline
a,b,q = map(int,input().split())
inf = float('inf')
S = [-inf]+[int(input()) for i in range(a)]+[inf]
T = [-inf]+[int(input()) for i in range(b)]+[inf]

def f(S,T):
    res = 10**30 
    s = bisect_left(S,x)

    ans = 0
    t = bisect_left(T,S[s-1])
    ans += abs(x-S[s-1])+min(abs(S[s-1]-T[t-1]),abs(S[s-1]-T[t]))
    if ans <= res:
        res = ans
    
    ans = 0
    t = bisect_left(T,S[s])
    ans += abs(x-S[s])+min(abs(S[s]-T[t-1]),abs(S[s]-T[t]))
    if ans <= res:
        res = ans

    return res


for i in range(q):
    x = int(input())
    print(min(f(S,T),f(T,S)))