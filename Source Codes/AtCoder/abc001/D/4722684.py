N=int(input())
Rain=[0 for i in range(60*24+2)]

for i in range(N):
    s,e=input().split("-")
    #print(S,E)
    sh=int(s[:2])*60
    sm=int(s[2:])
    S=((sh+sm)//5)*5
    eh=int(e[:2])*60
    em=int(e[2:])
    E=((eh+em+4)//5)*5
    Rain[S]+=1
    Rain[E]-=1
Rainsum=[Rain[0]]
for i in range(1,len(Rain)):
    Rainsum.append(Rainsum[i-1]+Rain[i])
    
#print(Rain)
Flag=0
out=""
for i in range(len(Rainsum)):
    if Flag==0 and Rainsum[i]>=1:
        Flag=1
        if i//60>=10:
            out+=str(i//60)
        elif i//60>=1:
            out+="0"+str(i//60)
        elif i//60==0:
            out+="00"
        if i%60>=10:
            out+=str(i%60)
        elif i%60>=1:
            out+="0"+str(i%60)
        elif i%60==0:
            out+="00"
        out+="-"
    elif Flag==1 and Rainsum[i]==0:
        Flag=0
        if i//60>=10:
            out+=str(i//60)
        elif i//60>=1:
            out+="0"+str(i//60)
        elif i//60==0:
            out+="00"
        if i%60>=10:
            out+=str(i%60)
        elif i%60>=1:
            out+="0"+str(i%60)
        elif i%60==0:
            out+="00"
        print(out)
        out=""