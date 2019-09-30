N=int(input())

is_o=[0,0,0,0,0,0,0,0,0]
ans=0
for i in range(N):
    s=list(input())
    for j in range(9):
        if s[j]=="x":
            if is_o[j]==1:
                ans+=1
                is_o[j]=0
            ans+=1
        elif s[j]=="o":
            is_o[j]=1
        else:
            if is_o[j]==1:
                ans+=1
                is_o[j]=0
print(ans+sum(is_o))