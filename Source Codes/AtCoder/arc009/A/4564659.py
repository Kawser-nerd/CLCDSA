n=int(input())
c=0
for i in range(n):
    a,b=map(int,input().split())
    c+=a*b
print(int(c*1.05))