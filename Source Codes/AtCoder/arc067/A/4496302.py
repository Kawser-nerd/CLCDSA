thelist=[2]
for i in range(3,1000):
        t=0
        for j in range(2,i):
            if i%j==0:
                t=1
                continue
        if t==0:
            thelist.append(i)
while True:
    try:
        n=int(input())
    except:
        break
    thedic={}
    for i in thelist:
        thedic[i]=0
    for i in range(1,n+1):
        t=i
        j=0
        while j!=len(thelist):
            if t%thelist[j]==0:
                thedic[thelist[j]]+=1
                t=t/thelist[j]
                continue
            j=j+1
            if t==1:
                break
    value=1
    for i in thedic:
        value=value%(1000000000+7)*(thedic[i]+1)
    print(value%(1000000000+7))