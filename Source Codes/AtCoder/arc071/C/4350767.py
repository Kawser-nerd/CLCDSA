import sys
input = sys.stdin.readline
s = list(input())
t = list(input())

snum = [(0,0)] #snum[j]-snum[i-1]:i-j????????(A,B)??
for i in range(len(s)):
    if s[i] == 'A':
        snum.append((snum[-1][0]+1,snum[-1][1]))
    else:
        snum.append((snum[-1][0],snum[-1][1]+1))

tnum = [(0,0)]
for i in range(len(t)):
    if t[i] == 'A':
        tnum.append((tnum[-1][0]+1,tnum[-1][1]))
    else:
        tnum.append((tnum[-1][0],tnum[-1][1]+1))

q = int(input())
for i in range(q):
    a,b,c,d = map(int,input().split())
    sa = snum[b][0]-snum[a-1][0]
    sb = snum[b][1]-snum[a-1][1]
    ta = tnum[d][0]-tnum[c-1][0]
    tb = tnum[d][1]-tnum[c-1][1]
    
    #??b???
    b1 = sb+sa*2
    b2 = tb+ta*2
    if abs(b2-b1)%3==0:
        print('YES')
        continue
    
    
    print('NO')