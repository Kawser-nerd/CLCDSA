n=int(input())

ans=n*(n+1)//2
#print(ans)
so=[1 for i in range(10**6+5)]
so[0]=0
so[1]=0
for i in range(2,1005):
    if so[i]==1:
        for j in range(2,10**6):
            if i*j>10**6:
                break
            else:
                so[i*j]=0
if so[ans]==1:
    print("WANWAN")
else:
    print('BOWWOW')