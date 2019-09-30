N=int(input())

ans=(N//11)*2
if(N%11>6):
        ans+=2
elif(N%11>0):
        ans+=1
print(ans)