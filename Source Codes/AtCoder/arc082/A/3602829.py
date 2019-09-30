lis=[0]*((10**5)+10)
N=int(input().strip())
a=list(map(int, input().split()))
for i in range(N):
    lis[a[i]-1]+=1
    lis[a[i]]+=1
    lis[a[i]+1]+=1
lis.sort(reverse=True)
print(lis[0])