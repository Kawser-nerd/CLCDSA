n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
c=[]
for i in range(n):
    c.append(sum(a[:i+1]+b[i:]))
print(max(c))