n,k=map(int,input().split())
a=(n-k)*(n-k+1)//2
for i in range(k+1,n):
    j=n//i*i
    a+=(j//i-1)*(i-k)+max(n-j+1-max(k,1),0)
print(a)