l=list(map(int,input().split()))
r=list(map(int,input().split()))
c=0
for i in range(7):
    c+=max(l[i],r[i])
print(c)