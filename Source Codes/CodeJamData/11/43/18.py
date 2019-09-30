def primelist(N):
    ps = [2]
    cur = 3
    for cur in range(3,N):
       for prime in ps:
           if prime*prime>cur:
               ps.append(cur)
               break
           if cur%prime ==0:
               break
    return ps

def run(plist):
    f=open("input.in")
    g=open("out.txt",'w')
    num = int(f.readline())
    for i in range(num):
        g.write("Case #%d: " % (i+1))
        n = int(f.readline())
        times = []
        for p in plist:
            if p^2>n:
                break
            else:
                count =0
                m=n/p
                while m>=p:
                    m=m/p
                    count=count+1
                if count>0:
                    times.append(count)
        if times:
            g.write("%d\n" %(sum(times)+1))
        elif n==1:
            g.write("0\n")
        else:
            g.write("1\n")
    f.close()
    g.close()
    
