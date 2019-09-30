import math
filename ="A-large.in"#"A-sample.in"
f= open(filename,'r')
out = open("output.txt",'w')
Cases= int(f.readline())
for T in range(Cases):
    [N,K]=[int(j) for j in f.readline().split(" ")]
    C=[[int(j) for j in f.readline().split(" ")] for i in range(N)]
    C=[[C[i][0],C[i][1],2*C[i][0]*C[i][1]] for i in range(len(C))]
    C=sorted(C, key=lambda x: -x[2])
    #print(C)
    maxR = 0
    side =0
    for i in range(K-1):
        maxR = max(maxR,C[i][0])
        side+=C[i][2]
    cura = maxR**2+side
    #print("cura "+str(cura))
    maxA =cura
    for i in range(K-1,N):
        maxA =max(maxA, cura+C[i][2]+max(0,C[i][0]**2-maxR**2))
        #print(maxA)
    ret=str(math.pi*maxA)
    ret="Case #"+str(T+1)+": "+ret
    print(ret)
    out.write(ret+"\n")
f.close()
out.close()
