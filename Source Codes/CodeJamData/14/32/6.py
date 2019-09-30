T=input()
M=1000000007

for tt in range(T):
    N=input()
    l=raw_input().split()
    ans=0
    sirve=True
    ans=1
    cc=0
    for x in range(26):
        s=0
        t=0
        c=0
        m=0
        for y in l:
            if len(y)>1 and y[0]!=chr(x+97) and y[-1]==chr(x+97):
                s+=1
            if len(y)>1 and y[0]==chr(x+97) and y[-1]!=chr(x+97):
                t+=1
            if len(y)>2 and y[0]!=chr(x+97) and y[-1]!=chr(x+97) and (chr(x+97) in y):
                m+=1
            if y==len(y)*chr(x+97):
                c+=1
        #print chr(x+97),m,s,t,c
        if m and (s or t or c):
            sirve=False
            break
        if s>1 or t>1:
            sirve=False
            break
        for z in range(c):
            ans=(ans*(z+1))%M
        if (not s) and (t or c): cc+=1
    for x in l:
        for i in range(len(x)):
            j=i+1
            while j<len(x) and x[i]!=x[j]: j+=1
            if j<len(x) and j>i+1:
                sirve=False
                break
    if not sirve: ans=0
    if cc==0: ans=0
    for z in range(cc):
        ans=(ans*(z+1))%M
    print "Case #%d: %d"%(tt+1,ans)
