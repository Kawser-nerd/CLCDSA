x,a,b=map(int,input().split())
ans='B'
if abs(x-a)<abs(x-b):
    ans='A'
print(ans)