data=[]
for i in range(1,30001):
    if i%2==0 or i%3==0:
        data.append(i)
k=int(input())
if k==3:
    print(*[2,5,63])
elif k==4:
    print(*[2,5,20,63])
elif k==5:
    print(*[2,5,20,63,30])
else:
    ans=data[:k]
    sm=sum(ans)
    if sm%6==2:
        ans[4]=30000
    elif sm%6==3:
        ans[5]=30000
    elif sm%6==5:
        ans[5]=29998
    print(*ans)