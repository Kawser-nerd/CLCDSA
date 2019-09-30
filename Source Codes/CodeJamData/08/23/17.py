
for case in range(input()):
    print "Case #"+str(case+1)+":",
    K=input()
    ind=map(int,raw_input().split())
    nind=ind.pop(0)
    pd=[-1]*K
    curloc=0
    empty=range(K)
    for i in range(K):
        curloc=(curloc+i)%len(empty)
        #print curloc
        pd[empty[curloc]]=i+1
        empty.pop(curloc)
        #print empty
    #pd=pd[1:]+[pd[0]]
    #print pd
    for i in ind:
        print pd[i-1],
    print
