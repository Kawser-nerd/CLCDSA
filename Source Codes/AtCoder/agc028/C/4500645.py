import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**9)
n=int(input())
Cost=[]
s1,s2=0,0
for i in range(n):
    a,b=map(int,input().split())
    s1+=a
    s2+=b
    Cost.append([a,i])
    Cost.append([b,i])
Cost.sort()
s3=sum([Cost[i][0] for i in range(n)])
if len(set([Cost[i][1] for i in range(n)]))==n:
    if Cost[n-1][1]==Cost[n][1]:
        s3+=min(Cost[n+1][0]-Cost[n-1][0],Cost[n][0]-Cost[n-2][0])
    else:
        s3+=Cost[n][0]-Cost[n-1][0]
print(min(s1,s2,s3))