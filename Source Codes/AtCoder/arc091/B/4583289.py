n,k=map(int,input().split())
sum=0
for i in range(k+1,n+1):
    x=n//i
    y=n%i
    sum+=x*(i-k)+max(y-k+1,0)
if k>0:
    print(sum)
else:
    print(sum-n)