n,x=map(int,input().split())
l=list(map(int,input().split()))
b=bin(x)[2:n+2]
if len(b)+1==n:
    b='0'+b
sum=0
for i in range(len(b)):
    sum+=l[len(b)-i-1]*int(b[i])
print(sum)