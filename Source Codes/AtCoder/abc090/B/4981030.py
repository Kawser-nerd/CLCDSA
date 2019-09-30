A,B=map(int,input().split())
ans=0
for i in range(A,B+1):
    i2=list(str(i))
    i3=list(reversed(i2))
    if i2==i3:
        ans+=1
    else:
        continue
print(ans)