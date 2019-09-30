import copy

N,M,D=map(int,input().split())
A=list(map(int,input().split()))

ANS=list(range(1,N+1))

for a in A:
    ANS[a-1],ANS[a]=ANS[a],ANS[a-1]
    #print(ANS)

#print(ANS)

LIST=[None]*N
for i in range(N):
    LIST[ANS[i]-1]=i+1

#print(LIST)

BINLIST=[LIST]

for i in range(35):
    NEXT=[None]*N

    for j in range(N):
        NEXT[j]=BINLIST[-1][BINLIST[-1][j]-1]

    BINLIST.append(NEXT)

#print(BINLIST)

ANS=list(range(1,N+1))

#print(bin(D)[::-1][:-2])

for j in range(len(bin(D)[::-1][:-2])):
    NEXT=[None]*N

    if bin(D)[::-1][:-2][j]=="1":
        for k in range(N):
            NEXT[BINLIST[j][k]-1]=ANS[k]
    else:
        NEXT=copy.copy(ANS)

    #print(j,ANS,NEXT)

    ANS=copy.copy(NEXT)

#LIST^D????????????

#print(ANS)

LIST=[None]*N
for i in range(N):
    LIST[ANS[i]-1]=i+1

#print(LIST)

for l in LIST:
    print(l)