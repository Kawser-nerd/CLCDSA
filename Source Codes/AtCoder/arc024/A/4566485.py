d=input()
l=list(map(int,input().split()))
r=list(map(int,input().split()))
c=0
for i in range(10,41):
    c+=min(l.count(i),r.count(i))
print(c)