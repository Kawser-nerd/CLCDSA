N,M=map(int,input().split())
ROAD=[None]*M

for i in range(M):
    ROAD[i]=tuple(sorted(list(map(int,input().split()))))
  
import itertools

NOROAD=list(itertools.combinations(range(1,N+1),2))

NOROAD=set(NOROAD) - set(ROAD)

Group=[[i,[]] for i in range(N+1)]

def find(x):
    while Group[x][0] != x:
        x=Group[x][0]
    return x


for i in NOROAD:
    a,b=i
    #print(a,b)
    Group[a][1]+=[b]
    Group[b][1]+=[a]

    if find(a) != find(b):
        Group[find(a)][0]=min(find(a),find(b))
        Group[find(b)][0]=min(find(a),find(b))
        Group[a][0]=min(find(a),find(b))
        Group[b][0]=min(find(a),find(b))

GroupSORT=[[i,j[1]] for i,j in enumerate(Group)]
GroupSORT.sort(key=lambda x:len(x[1]))
NUMBERING=[[find(i),"none"] for i in range(N+1)]
CHECK=[0 for i in range(N+1)]

for i in range(N):
    if CHECK[find(GroupSORT[i][0])]==0:
        
        NUMBERING[GroupSORT[i][0]][1]=0
        CHECK[find(GroupSORT[i][0])]=1

CONDITION=1
#print(NUMBERING)


repeat_condition=1
while repeat_condition==1:

    repeat_condition=0

    for i in range(1,N+1):
        if NUMBERING[i][1]==0:
            for j in Group[i][1]:
                if NUMBERING[j][1]==0:
                    CONDITION=0
                    break
                elif NUMBERING[j][1]=="none":
                    NUMBERING[j][1]=1
                    repeat_condition=1

        if NUMBERING[i][1]==1:
            for j in Group[i][1]:
                if NUMBERING[j][1]==1:
                    CONDITION=0
                    break
                elif NUMBERING[j][1]=="none":
                    NUMBERING[j][1]=0
                    repeat_condition=1


import sys
if CONDITION==0:
    print(-1)
    sys.exit()

NUMBERS=set()
for i in range(1,len(NUMBERING)):
    NUMBERS=NUMBERS|{NUMBERING[i][0]}

count=[]
for i in NUMBERS:
    count+=[(i,NUMBERING.count([i,0]),NUMBERING.count([i,1]))]

DP=[set() for i in range(len(count))]
DP[0]={count[0][1],count[0][2]}

for i in range(1,len(count)):
    for k in DP[i-1]:
        DP[i]=DP[i]|{k+count[i][1],k+count[i][2]}

DIVIDE=list(DP[len(count)-1])
#print(DIVIDE)
for i in range(len(DIVIDE)):
    DIVIDE[i]=abs(DIVIDE[i]-N/2)

x=int(min(DIVIDE)+N/2)

print(x*(x-1)//2+(N-x)*(N-x-1)//2)