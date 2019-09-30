import math
filename ="C-small-1-attempt0.in"#"C-large.in"
f= open(filename,'r')
out = open("output.txt",'w')
Cases= int(f.readline())
for T in range(Cases):
    [N,K]=[int(j) for j in f.readline().split(" ")]
    U= float(f.readline())
    P=[float(j) for j in f.readline().split(" ")]
    #print("U: "+str(U))
    #print("P: "+str(P))
    P=sorted(P)+[1.0]#haxx
    Ubuf=U
    i=0
    #print(P)
    while(Ubuf>=0)and(i<len(P)-1):
        #print(str([i,Ubuf]))
        Ubuf -=(P[i+1]-P[i])*(i+1)
        i+=1
    #print("i "+str(i))
    Pr=P[i]+Ubuf/i
    for j in range(i):
        P[j] =Pr
    #print("nuP "+str(P))
    Pr=1.0
    for p in P:
        Pr*=p
    ret=str(Pr)
    ret="Case #"+str(T+1)+": "+ret
    print(ret)
    out.write(ret+"\n")
f.close()
out.close()
