import sys
input = sys.stdin.readline 
N,A,B = map(int,input().split())
a = [int(input()) for _ in range(N)]
a_min = min(a)
a_max = max(a)
if a_min != a_max:
    p = B / (a_max - a_min)
    #print('p:',p)
    q = A - (sum(a)) * p / N
    #print('q:',q)
    print(p,q)
else:
    #print('same points. no answer')
    print(-1)