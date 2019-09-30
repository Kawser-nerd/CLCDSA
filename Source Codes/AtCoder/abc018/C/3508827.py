import copy

R,C,K=map(int,input().split())
S=[list(input()) for i in range(R)]
#print()
from collections import deque
QUE=deque()

for i in range(R):
    for j in range(C):
        if S[i][j]=="x":
            QUE.append((i,j))

for k in range(K-1):
    NQUE=deque()
    while QUE:
        x,y=QUE.pop()
        
        for i,j in [(x+1,y),(x-1,y),(x,y+1),(x,y-1)]:
            if 0<=i<R and 0<=j<C and S[i][j]=="o":
                S[i][j]="x"
                NQUE.append((i,j))


#    for i in range(R):
#        for j in range(C):
#            print(S[i][j],end="")
#        print()
#    print()
    QUE=copy.copy(NQUE)




ANS=0
for i in range(K-1,R-K+1):
    for j in range(K-1,C-K+1):
        if S[i][j]=="o":
            ANS+=1

print(ANS)