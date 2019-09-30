N=input()

cnt=0
for i in N:
    cnt+=int(i)
if int(N)%cnt==0:
    print('Yes')
else:
    print('No')