n=int(input())
x=list(map(int, input().split()))
a=list(range(1,n*30000+1,30000))
b=list(range(n*30000,0,-30000))
for i,j in enumerate(x):
    b[j-1]+=i
print(*a)
print(*b)