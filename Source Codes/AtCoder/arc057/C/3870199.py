root=int(input())
inf=root**2
sup=(root+1)**2
tmp1=sup
tmp2=inf
ans=sup+1
times=0
while(tmp1>0):
    tmp1//=100        #?????????????
    times+=1
    if tmp1*100**times>=inf and tmp1*100**times<sup:
        ans=min(ans,tmp1)
times=0
while(tmp2>0):
    tmp2=(tmp2+99)//100        #????????????
    times+=1
    if tmp2*100**times>=inf and tmp2*100**times<sup:
        ans=min(ans,tmp2)
    if 100**times>sup:
        break
ans=min(root**2,ans)
print(ans)