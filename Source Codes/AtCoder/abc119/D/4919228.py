from bisect import*
a,b,q=map(int,input().split())
a1=[int(input())for i in range(a)]
b1=[int(input())for i in range(b)]
q=[int(input())for i in range(q)]
 
a1=[-20**10]+a1+[20**10]
b1=[-20**10]+b1+[20**10]
 
for i in q:
    x=bisect_left(a1,i)
    y=bisect_left(b1,i)
    low =i-min(a1[x-1],b1[y-1])
    high=max(a1[x],b1[y])-i
    turn1=min(a1[x]-i,i-b1[y-1])+abs(a1[x]-b1[y-1])
    turn2=min(b1[y]-i,i-a1[x-1])+abs(b1[y]-a1[x-1])
    print(min(low,high,turn1,turn2))