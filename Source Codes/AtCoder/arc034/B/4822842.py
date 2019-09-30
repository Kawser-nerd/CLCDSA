n=int(input())
ans=[]
cnt=0
#????10**18-1(=9*17)=153??????
for i in range(max(n-153,0),n+1):
    if i+sum([int(j) for j in str(i)])==n:
        cnt+=1
        ans.append(i)
print(cnt)
if cnt!=0:
    print(*ans,sep='\n')