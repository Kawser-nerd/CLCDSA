import copy
from collections import deque

R,C,K = map(int,input().split())
S = [list(input()) for i in range(R)]
QUE=deque()
ans = 0
 
for i in range(R):
    for j in range(C):
        if S[i][j] == "x":
            QUE.append((i,j))
 
for k in range(K-1):
    NQUE = deque()
    while QUE:
        x,y = QUE.pop()
        
        for i,j in [(x+1,y),(x-1,y),(x,y+1),(x,y-1)]:
            if 0<= i <= R-1 and 0<= j <=C-1 and S[i][j] == "o":
                S[i][j] = "x"
                NQUE.append((i,j))
    QUE = copy.copy(NQUE)

for i in range(K-1, R-K+1):
    for j in range(K-1, C-K+1):
        if S[i][j]=="o":
            ans += 1
 
print(ans)