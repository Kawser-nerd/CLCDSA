T=int(input())

def sqSize(b, v, M, N, i, j):
    s = 0
    while True:
        if s + i >= M or s + j >= N:
            return s
        for ii in range(0, s+1):
            if b[i+ii][s+j] != v:
                return s
            if b[s+i][j+ii] != v:
                return s
        s+=1

def fill(b,m,i,j):
    for ii in range(i,i+m):
        for jj in range(j,j+m):
            b[ii][jj]=None

def findSq(b,M, N):
    mi=0
    mj=0
    m=0
    for i in range(0,M):
        for j in range(0, N):
            if b[i][j] == None:
                continue
            s = sqSize(b,b[i][j],M,N,i,j)
            if s > m:
                m=s
                mi=i
                mj=j
    fill(b,m,mi,mj)
    return m

for testCase in range(0,T):
    line=input().split()
    M=int(line[0])
    N=int(line[1])
    b=[]
    for i in range(0,M):
        r=[int(j,16) for j in input()]
        row=[]
        for num in r:
            for s in range(0,4):
                row.append(num & (1 << (3-s)) != 0) 
        b.append(row)
    for i in range(0,M):
        for j in range(0,N):
            if (i + j)%2:
                b[i][j] = not b[i][j]

    d={}
    while True:
        m=findSq(b,M,N)
        if m==0:
            break
        if not (m in d):
            d[m]=0
        d[m]+=1
    
    print('Case #{0}: {1}'.format(testCase+1, len(d)))
    keys=[k for k in d.keys()]
    keys.sort()
    keys.reverse()
    for k in keys:
        print(k,d[k])

