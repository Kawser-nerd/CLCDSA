import sys
import bisect
input=sys.stdin.readline
N=int(input())
data=[tuple(map(int,input().split())) for _ in range(N)]
data.sort()
data2=[]
now=[]
for d in data:
    if len(now)==0:
        now.append(d)
        continue
    if now[0][0]!=d[0]:
        now.sort(key=lambda x:x[1],reverse=True)
        data2+=now
        now=[d]
    elif now[0][0]==d[0]:
        now.append(d)
now.sort(key=lambda x:x[1],reverse=True)
data2+=now
data=data2
inf=float('inf')
dp=[inf]*(len(data)+1)
dp[0]=0
dp2=[(inf,inf)]*(len(data)+1)
dp2[0]=(0,0)
for i in range(len(data)):
    idx=bisect.bisect_left(dp,data[i][1])
    if dp2[idx-1][0]<data[i][0] and data[i][1]<dp2[idx][1]:
        dp[idx]=data[i][1]
        dp2[idx]=data[i]
    
print(len([i for i in dp if i<inf])-1)