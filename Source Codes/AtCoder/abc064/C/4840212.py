N=int(input())
a=list(map(int,input().split()))
color=[0]*9
for i in range(N):
    if a[i]//400>=8:
        color[8]+=1
    else:
        color[a[i]//400]+=1
cnt=0
for i in range(8):
    if color[i]>0:
        cnt+=1
mx=cnt+color[8]
if cnt>0:
    mn=cnt
else:
    mn=1
print(mn,mx)