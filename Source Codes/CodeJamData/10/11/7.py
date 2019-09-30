#!/usr/bin/python3
# -*- coding: utf-8 -*-

inp = open('input.txt','r')
outp = open('output.txt','w')

T = int(inp.readline())
for i in range(T):
    N,K=map(int,inp.readline().split())
    S = [inp.readline().strip().replace('.','').rjust(N,'.') for x in range(N)]
    ls=[[0,'0'] for x in range(N)]
    rs=[[0,'0'] for x in range(N)]
    ts=[[0,'0'] for x in range(N)]
    fins = set()
    for x in S:
        bs=[0,'0']
        lsn = []
        rsn = []
        for y in range(N):
            if bs[1]==x[y]:
                bs[0]+=1
            else:
                bs[0]=1
                bs[1]=x[y]
            if ts[y][1]==x[y]:
                ts[y][0]+=1
            else:
                ts[y][0]=1
                ts[y][1]=x[y]
            if y==0:
                lsn.append([1,x[y]])
            elif ls[y-1][1]==x[y]:
                lsn.append((ls[y-1][0]+1,x[y]))
            else:
                lsn.append((1,x[y]))
            if y==N-1:
                rsn.append(([1,x[y]]))
            elif rs[y+1][1]==x[y]:
                rsn.append((rs[y+1][0]+1,x[y]))
            else:
                rsn.append((1,x[y]))
            if (bs[0]==K or ts[y][0]==K or lsn[-1][0]==K or rsn[-1][0]==K) and x[y]!='.':
                fins.add(x[y])
        rs = rsn
        ls = lsn
    ans = {
        ''  : "Neither",
        'B' : "Blue",
        'R' : "Red"
    }
    print ("Case #%d: %s"%(i+1,ans.get(''.join(fins),'Both')),file=outp)
