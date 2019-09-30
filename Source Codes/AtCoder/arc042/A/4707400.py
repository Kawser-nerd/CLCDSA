import sys
input = sys.stdin.readline 

N,M = map(int,input().split())
a = [int(input()) for _ in range(M)]
a.reverse()

#print(a)
b = set()
#set_b = set(b)
for c in a:
    if not c in b:
        print(c)
        b.add(c)
#print(b)
if len(b) < N:
    d = set([i for i in range(1,N+1)]) - b
    for i in sorted(list(d)):
        print(i)