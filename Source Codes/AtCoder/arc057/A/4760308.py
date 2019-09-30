a,k=[int(i) for i in input().split()]
if k==0:
    print(2*(10**12)-a)
else:
    ans=a
    cnt=0
    while ans<2*(10**12):
        cnt+=1
        ans+=ans*k+1
    print(cnt)