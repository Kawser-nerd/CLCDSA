import math
filename ="B-large.in"
f= open(filename,'r')
out = open("output.txt",'w')
Cases= int(f.readline())
for T in range(Cases):
    [Ac,Aj]=[int(j) for j in f.readline().split(" ")]
    Ca=[[int(j) for j in f.readline().split(" ")]+[0] for i in range(Ac)]
    Ja=[[int(j) for j in f.readline().split(" ")]+[1] for i in range(Aj)]
    A=sorted(Ca+Ja)
    #print(A)
    forcedTime =[0,0]
    vartime =0
    betw=[[],[]]
    swaps =0
    # midnight
    forcedTime[A[0][2]]+=A[0][1]-A[0][0]
    if A[0][2]!=A[len(A)-1][2]:
        vartime+= A[0][0]-A[len(A)-1][1]+1440
        swaps+=1
    else:
        betw[A[0][2]]+=[A[0][0]-A[len(A)-1][1]+1440]
    #and the rest
    for i in range(1,len(A)):
        forcedTime[A[i][2]]+=A[i][1]-A[i][0]
        if A[i][2]!=A[i-1][2]:
            vartime+= A[i][0]-A[i-1][1]
            swaps+=1
        else:
            betw[A[i][2]]+=[A[i][0]-A[i-1][1]]
    #print("forced "+str(forcedTime))
    #print("var "+str(vartime))
    
    betw[0]=sorted(betw[0],key = lambda x:-x)
    betw[1]=sorted(betw[1],key = lambda x:-x)
    #print("betw "+str(betw))
    tofix = forcedTime[0]+sum(betw[0])-forcedTime[1]-sum(betw[1])
    if tofix <0:
        tofix =-tofix
        betw  =[betw[1],betw[0]]
    tofix-=min(vartime,tofix)
    i=0
    while tofix >0:
       tofix -=min(tofix, 2*betw[0][i])
       swaps+=2
       i+=1
    ret=str(swaps)
    ret="Case #"+str(T+1)+": "+ret
    print(ret)
    out.write(ret+"\n")
f.close()
out.close()
