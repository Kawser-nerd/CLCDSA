def mincos(n,ab):
    aball=[]
    aball+=[(ab[i][0],i+1,'a') for i in range(n)]
    aball+=[(ab[i][1],i+1,'b') for i in range(n)]
    aball.sort()
    
    ans1=sum([i[0] for i in aball[:n]])

    hen=aball[n][0]
    hen2=aball[n+1][0]
    d=set()
    t=None
    hantei=True
    for i,c,mab in aball[:n]:
        if t!=None and t!=mab:
            hantei=False
        if  c in d:
            print(ans1)
            exit()
        d.add(c)
        t=mab

    if hantei:
        print(ans1)
        exit()

    ans2=[]
    for i,c,aorb in aball[:n]:
        if aball[n][1]!=c:
            ans2+=[ans1-i+hen]
        else:
            ans2+=[ans1-i+hen2]
    print(min(ans2))
    exit()

n=int(input())
print(mincos(n,[list(map(int,input().split())) for i in range(n)]))