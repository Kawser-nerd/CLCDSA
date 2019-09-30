while True:
    try:
        n,a,b=map(int,input().split())
    except:
        break
    thelist=list(map(int,input().split()))
    t=b//a
    sum=0
    for i in range(1,n):
        tt=thelist[i]-thelist[i-1]
        if tt>t:
            sum+=b
        else:
            sum+=a*tt
    print(sum)