from collections import defaultdict,deque
import sys,heapq,bisect,math,itertools,string,queue,datetime
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-7
def inp(): return int(input())
def inpl(): return list(map(int, input().split()))
def inpls(): return list(input().split())

N = int(input())
ans3 = [3*(i*2+1) for i in range(5000)]
ans2 = [2*(i+1) for i in range(15000)]

if N == 3:
    print(2,5,63)
elif N == 4:
    print(2,5,20,63)
elif N == 6:
    print(3,6,9,12,2,4)
elif N == 19999:
    ans = ans2[:14999]+ans3
    print(' '.join(map(str,ans)))
else:
    for x in range(1,2501):
        if (N-x*2)%3 == 0:
            y = (N-x*2)//3
            if 1 <= y <= 5000:
                ans = ans3[:x*2]+ans2[:y*3]
                break
    print(' '.join(map(str,ans)))