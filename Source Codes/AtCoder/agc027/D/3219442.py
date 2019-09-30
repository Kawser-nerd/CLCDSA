N = int(input())
if N == 2:
    print(4,7)
    print(23,10)
    exit()

MAXN = 8000
sieve = [0,0] + [1]*MAXN
primes = []
p = 2
while p*p <= MAXN:
    if sieve[p]:
        primes.append(p)
        for q in range(2*p,MAXN+1,p):
            sieve[q] = 0
    p += 1
for q in range(p,MAXN):
    if sieve[q]:
        primes.append(q)

mem = [[[] for j in range(N)] for i in range(N)]
pi = 0
for i in range(0,2*N-1,4):
    for x in range(N):
        y = i-x
        if y >= N: continue
        if y < 0: break
        mem[y][x].append(primes[pi])
    pi += 1
for i in reversed(range(2,2*N-1,4)):
    for x in range(N):
        y = i-x
        if y >= N: continue
        if y < 0: break
        mem[y][x].append(primes[pi])
    pi += 1

ini = -((N-1)//2*2)
for i in range(ini,N,4):
    for x in range(N):
        y = x-i
        if y < 0: continue
        if y >= N: break
        mem[y][x].append(primes[pi])
    pi += 1
for i in range(ini+2,N,4):
    for x in range(N):
        y = x-i
        if y < 0: continue
        if y >= N: break
        mem[y][x].append(primes[pi])
    pi += 1

ans = [[None]*N for i in range(N)]
dxy = [(1,0),(0,1),(-1,0),(0,-1)]
for y in range(N):
    for x in range(N):
        if (x+y)%2:
            pset = set()
            for dx,dy in dxy:
                nx,ny = x+dx,y+dy
                if not 0 <= nx < N: continue
                if not 0 <= ny < N: continue
                pset.add(mem[ny][nx][0])
                pset.add(mem[ny][nx][1])
            a = 1
            for p in pset:
                a *= p
            ans[y][x] = a+1
        else:
            ans[y][x] = mem[y][x][0] * mem[y][x][1]

for row in ans:
    print(*row)