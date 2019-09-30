import sys
N=int(input())
a=-1
v=-1
for i in range(2,N+1):
    print("? {0} {1}".format(1, i))
    sys.stdout.flush()
    dist = int(input())
    if dist>a:
        a=dist
        v=i
ans=-1
for i in range(1,N+1):
    if i==v:
        continue
    print("? {0} {1}".format(v, i))
    sys.stdout.flush()
    dist = int(input())
    if dist>ans:
        ans=dist
print("!",ans)