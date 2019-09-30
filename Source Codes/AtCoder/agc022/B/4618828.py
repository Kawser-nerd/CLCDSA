n=int(input())
if n==3:
    ans=[2,5,63]
elif n==4:
    ans=[2,5,20,63]
elif n==5:
    ans=[2,3,4,6,9]
else:
    ans=[]
    cnt,s=0,0
    for i in range(2,30001):
        if i%2==0 or i%3==0:
            ans.append(i)
            cnt+=1
            s+=i
        if cnt==n:
            break
    if s%6==2:
        ans.remove(8)
        ans.append((i//6)*6+6)
    elif s%6==3:
        ans.remove(9)
        ans.append((i//6)*6+6)
    elif s%6==5:
        ans.remove(9)
        ans.append(((i+2)//6)*6+4)
print(*ans)