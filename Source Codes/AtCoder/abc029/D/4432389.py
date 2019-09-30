N=int(input())
ans=0

for i in range(9):
    A=(N//(10**(i)))
    #print(A,i)
    if (A)%10==1:
        ans+=(A//10)*(10**i)
        ans+=(N%(10**(i))+1)
    elif (A)%10>1:
        ans+=(A//10+1)*(10**i)
    else:
        ans+=(A//10)*(10**i)
    #print(ans,i)
print(ans)