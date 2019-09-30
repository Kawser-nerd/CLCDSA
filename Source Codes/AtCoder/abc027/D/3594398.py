S=input()
LEN=len(S)

PC=[0 for i in range(LEN)]
MC=[0 for i in range(LEN)]

for i in range(LEN):
    if S[i]=="+":
        PC[i]+=1
    elif S[i]=="-":
        MC[i]+=1

SUMPC=[0]
for i in range(LEN-1,-1,-1):
    SUMPC.append(SUMPC[-1]+PC[i])

SUMMC=[0]
for i in range(LEN-1,-1,-1):
    SUMMC.append(SUMMC[-1]+MC[i])

SUMPC=SUMPC[1:][::-1]
SUMMC=SUMMC[1:][::-1]

MSC=[]
for i in range(LEN):
    if S[i]=="M":
        MSC.append(SUMPC[i]-SUMMC[i])


LENSC=len(MSC)
MSC.sort()

ANS=0
for i in range(LENSC//2):
    ANS+=-MSC[i]
for j in range(i+1,LENSC):
    ANS+=MSC[j]

print(ANS)