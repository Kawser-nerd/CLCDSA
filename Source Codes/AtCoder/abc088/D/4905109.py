H,W = list(map(int,input().split()))

M=[]

w_count=0

for i in range(H):
    s=input()
    m=[]
    for j in range(W):
        if s[j]=='.':
            m.append(0)
            w_count+=1
        else:
            m.append(1)
    M.append(m)

path = [[[] for j in range(W)] for i in range(H)]

for i in range(H):
    for j in range(W):
        if M[i][j]==0:
            if i!=H-1:
                if M[i+1][j]==0:
                    path[i][j].append([i+1,j])
                    path[i+1][j].append([i,j])
            if j!=W-1:
                if M[i][j+1]==0:
                    path[i][j].append([i,j+1])
                    path[i][j+1].append([i,j])

M_path = [[10**27 for j in range(W)] for i in range(H)]
M_checked = [[False for j in range(W)] for i in range(H)]
M_path[0][0]=0

from collections import deque

Q=deque([[0,0]])
M_checked[0][0]=True
while len(Q)>0:
    i,j=Q.pop()
    mp = M_path[i][j]
    for p in path[i][j]:
        if not M_checked[p[0]][p[1]]:
            M_checked[p[0]][p[1]]=True
            Q.appendleft(p)
            if mp+1 < M_path[p[0]][p[1]]:
                M_path[p[0]][p[1]] = mp+1

if M_path[H-1][W-1]<10**27:
    print(w_count-(M_path[H-1][W-1]+1))
else:
    print(-1)