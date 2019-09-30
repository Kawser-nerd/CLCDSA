from collections import defaultdict,deque
import sys,heapq,bisect,math,itertools,string,queue,datetime
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
def inpl(): return list(map(int, input().split()))
def inpls(): return list(input().split())

N = int(input())

#?????
def gcd(a,b):
	while b:
		a,b = b, a%b
	return a

#?????
def lcm(a,b):
	return a*b // gcd(a,b)

def hurui(n):
    data = [i for i in range(2, n + 1)]
    for d in data:
        data = [x for x in data if (x == d or x % d != 0)]
    return data

Primes = hurui(8000)

pn = []
for p in Primes:
	pn.append(p)

ans = [[0]*N for i in range(N)]
for y in range(N):
	if y%2 == 0:
		xx = range(0,N,2)
	else:
		xx = range(1,N,2)

	for x in xx:
		pl = (y+x)//2
		mn = (y-x)//2 + N + (N-1)//2
		ans[y][x] = pn[pl]*pn[mn]

ed = defaultdict(bool)
for y in range(N):
    for x in range(N):
        if ans[y][x] == 0:
            tmp = 1
            if x > 0:
                tmp = lcm(tmp,ans[y][x-1])
            if x < N-1:
                tmp = lcm(tmp,ans[y][x+1])
            if y > 0:
                tmp = lcm(tmp,ans[y-1][x])
            if y < N-1:
                tmp = lcm(tmp,ans[y+1][x])

            while ed[tmp+1]:
                tmp += tmp

            ans[y][x] = tmp + 1
            ed[tmp+1] = True

for a in ans:
    print(' '.join(map(str,a)))