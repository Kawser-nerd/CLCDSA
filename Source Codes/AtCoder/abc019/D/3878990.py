import sys
N = int(input())

maxd = v = 0
for i in range(2,N+1):
    print('?',1,i)
    sys.stdout.flush()
    dist = int(input())
    if dist > maxd:
        maxd = dist
        v = i

maxd = w = 0
for i in range(1,N+1):
    if i == v: continue
    print('?',v,i)
    sys.stdout.flush()
    dist = int(input())
    if dist > maxd:
        maxd = dist
        w = i

print('!',maxd)