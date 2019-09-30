from bisect import*
a,b,q=map(int,input().split())
a1=[int(input())for i in range(a)]
b1=[int(input())for i in range(b)]
q=[int(input())for i in range(q)]

mama=max(a1[-1],b1[-1])
mami=min(a1[-1],b1[-1])
mimi=min(a1[0],b1[0])
mima=max(a1[0],b1[0])

a1=[-20**10]+a1+[20**10]
b1=[-20**10]+b1+[20**10]

#print(mama,mami,mima,mimi)
for i in q:
    if i>=mama:
        print(i-mami)
    elif i<=mimi:
        print(mima-i)
    else:
        x=bisect_left(a1,i)
        y=bisect_left(b1,i)
        #print(a1[x-1],a1[x],b1[y-1],b1[y])
        low =i-min(a1[x-1],b1[y-1])
        high=max(a1[x],b1[y])-i
        turn1=min(a1[x]-i,i-b1[y-1])+abs(a1[x]-b1[y-1])
        turn2=min(b1[y]-i,i-a1[x-1])+abs(b1[y]-a1[x-1])
        print(min(low,high,turn1,turn2))
#print(a1,b1,q)