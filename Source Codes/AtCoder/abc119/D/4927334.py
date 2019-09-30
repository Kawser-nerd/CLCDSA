import bisect,sys
input = sys.stdin.readline
a,b,q = map(int,input().split())
INF = float('inf')
S = [-INF]+[int(input()) for i in range(a)]+[INF]
T = [-INF]+[int(input()) for i in range(b)]+[INF]

def f(S,T):
    res = INF
    s = bisect.bisect_left(S,x)
    for i in range(2):
    	for j in range(2):
            t = bisect.bisect_left(T,S[s-i])
            ans= abs(x-S[s-i])+abs(S[s-i]-T[t-j])
            if ans < res:
                res = ans
    return res

for i in range(q):
    x = int(input())
    print(min(f(S,T),f(T,S)))