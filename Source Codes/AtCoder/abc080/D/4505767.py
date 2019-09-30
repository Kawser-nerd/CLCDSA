ri = lambda: int(input())
rl = lambda: list(map(int,input().split()))
rr = lambda N: [ri() for _ in range(N)]
YN = lambda b: print('YES') if b else print('NO')
yn = lambda b: print('Yes') if b else print('No')
OE = lambda x: print('Odd') if x%2 else print('Even')
INF = 10**18

N,C=rl()
stc = [rl() for _ in range(N)]
stc.sort(key=lambda x:(x[2],x[0]))
nstc = []
for s,t,c in stc:
    if len(nstc) != 0 and nstc[-1][2] == c and nstc[-1][1] == s:
        nstc[-1][1] = t
    else:
        nstc.append([s,t,c])

n = len(nstc)

TT=[0]*(2*10**5+5)
for i in range(n):
    TT[2*nstc[i][0] - 1] += 1
    TT[2*nstc[i][1]] -= 1
for i in range(1,len(TT)):
    TT[i] += TT[i-1]
print(max(TT))