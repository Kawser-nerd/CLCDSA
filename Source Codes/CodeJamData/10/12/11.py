def read():
    D,I,M,nVal = map(int,raw_input().split())
    val = map(int,raw_input().split())
    return D,I,M,val


def rec(lastV,idx,D,I,M,val,dp):
    if idx==len(val): return 0
    ret = dp[lastV][idx]
    if ret!=-1: return ret

    ret = 1<<30

    # insert
    if lastV!=256 and abs(lastV-val[idx])>M and M!=0:
        absV = abs(lastV-val[idx])
        ret = min(ret,rec(val[idx],idx+1,D,I,M,val,dp)+max(0,(absV/M-(absV%M==0))*I))

    # delete
    ret = min(ret,rec(lastV,idx+1,D,I,M,val,dp)+D)

    # change
    if lastV==256:
        for i in range(0,256):
            ret = min(ret,rec(i,idx+1,D,I,M,val,dp)+abs(val[idx]-i))
    else:
        for i in range(0,256):
            if abs(lastV-i)<=M:
                ret = min(ret,rec(i,idx+1,D,I,M,val,dp)+abs(val[idx]-i))        

    dp[lastV][idx] = ret
    return ret

    
def work(cases,(D,I,M,val)):
    dp = [[-1 for j in range(len(val))] for i in range(257)] 
    print "Case #%d: %d"%(cases,rec(256,0,D,I,M,val,dp))


for i in range(int(raw_input())):
    work(i+1,read())
