def solve(a):
    if len(a)==0:
        return 0
    #print a
    b = []
    cur = a[0]-1
    cnt = 0
    for x in a:
        if x==cur:
            cnt+=1
        else:
            b.append(cnt)
            cnt = 1
            cur = x
    b.append(cnt)
    
    res = 100000
    Q = []
    b.append(0)
    for i in range(1,len(b)):
        while b[i]>b[i-1]:
            Q.append(i)
            b[i-1]+=1
        while b[i]<b[i-1]:
            x = Q.pop(0)
            b[i-1]-=1
            res = min(res,i-x)
    return res

fi = open("input.txt")
for turn in range(int(fi.readline())):
    a = map(int,fi.readline().split())
    n = a.pop(0)
    assert n == len(a)
    
    a.sort()
    res = 100000
    
    i = 0
    for j in range(1,len(a)):
        if a[j]>a[j-1]+1:
            res= min(res,solve(a[i:j]))
            i = j       
            
    res = min(res,solve(a[i:len(a)]))
        
    print "Case #{0}: {1}".format(turn+1,res)
