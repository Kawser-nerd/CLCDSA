
import sys
sys.stdin=open("data.txt")
sys.stdout=open("out.txt","w")
input=sys.stdin.readline
sys.setrecursionlimit(10000)

g=[]
friend=[]

# method for finding the longest cycle in O(N^2)
def dfs(u,n):
    # check if part of a chain
    v=u
    for i in range(1,n+2):
        v=friend[v]
        if u==v: return i
    else:
        return 1

# two methods for finding all pairs
def depth(u,bad):
    # find the distance to the bottom from node u
    out=0
    for v in g[u]:
        if v!=bad:
            out=max(out,depth(v,bad))
    return out+1

def getpairs():
    out=0
    for i in range(len(g)):
        if friend[friend[i]]==i:
            out+=depth(i,friend[i])+depth(friend[i],i)
    return out//2

for c in range(int(input())):
    n=int(input())
    friend=list(map(lambda s:int(s)-1,input().split()))
    ans=0
    # make the backwards graph
    g=[[] for _ in range(n)]
    for i in range(n):
        g[friend[i]].append(i)
    # get the best root
    for i in range(n):
        ans=max(ans,dfs(i,n))
    ans=max(ans,getpairs())
    # print answer
    print("Case #%s: %s"%(c+1,ans))
