n=int(input())
k=int(input())
x=list(map(int,input().split()))
l=0
for i in range(n):
    l+=2*min(x[i],abs(k-x[i]))
print(l)