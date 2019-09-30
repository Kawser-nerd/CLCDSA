h,w=map(int,input().split())
n=int(input())
a=list(map(int,input().split()))

l=[]
for i in range(n):
    for j in range(a[i]):
      l.append(i+1)
ans=[]
for i in range(h):
    if i%2==1:
        x=l[i*w:(i+1)*w]
        ans.append(x[::-1])
    else:
        ans.append(l[i*w:(i+1)*w])
for i in range(h):
    print(*ans[i])