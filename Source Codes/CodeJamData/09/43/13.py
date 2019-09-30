f = open('C_Rnd2.in', 'r')
out=open('C_Rnd2.out','w')
cases = int(f.readline()[:-1])



def canoverlay(a1,a2):
    flag1=True
    flag2=True
    for i in range(len(a1)):
        if a1[i]>=a2[i]:
            flag1=False
            break
    for i in range(len(a1)):
        if a1[i]<=a2[i]:
            flag2=False
            break
    return flag1 or flag2


color=[]
col = 0


def customCompare(host1, host2):
    if len(host1)==len(host2):
        return host1<=host2
    elif len(host1)<len(host2):
        return 1
    else: return -1

def cc2(x,y):
    return customCompare(x[1],y[1])

def find(n,adj,dp):
    dp.sort(customCompare)
    #print 'find',n,adj,dp
    for i in range(len(dp)):
        arr=dp[i]
        flag = False
        for j in arr:
            if n not in adj[j]:
                flag=True
        if not flag:
            return i

    return len(dp)+1



for case in range(1,cases+1):
    s=f.readline()[:-1].split()
    n=int(s[0]);k=int(s[1])
    arr=[]
    for i in range(n):
        s=f.readline()[:-1].split()
        arr.append([int(x) for x in s])
    arr.sort()
    adj=[]
    for i in range(n):
        adj.append([])
        for j in range(n):
            if canoverlay(arr[i],arr[j]):
                adj[-1].append(j)
                
#    color=[0]*len(arr)
#    col=0
#    print n,k,arr,adj
#    for i in range(n):
#        if color[i]==0:
#            col+=1
#            a=flood(i,adj,[x for x in range(n) if color[x]==0])
#            print a
#            for el in a:
#                color[el]=col
#    print color,col
    print n,k,adj
    adj2=[[i,adj[i]] for i in range(len(adj))]
    adj2.sort(cc2)
    adj2.reverse()
    
    ord=[adj2[i][0] for i in range(len(adj))]
    adj=[adj2[i][1] for i in range(len(adj))]
    #print ord,adj
    dp=[[1,[[0]]]]
    for i in range(1,n):
        x=adj2[i][0]
        
        k=dp[i-1][1]
        q=find(x,adj,dp[i-1][1])
        if q<dp[i-1][0]:
            k[q].append(i)
        else: k.append([i])
        dp.append([len(k),k])
    print dp[n-1]
    out.write("Case #"+str(case)+": "+str(dp[n-1][0])+"\n")
   
