n,q=map(int,input().split())
a=[0]*n
for i in range(q):
        l,r,t=map(int,input().split())
        for j in range(l-1,r):
                a[j]=t
for i in range(len(a)):
        print(a[i])