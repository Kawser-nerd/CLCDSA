h,w,n=map(int, input().split())
m=dict()
for _ in range(n):
    a,b=map(int, input().split())
    for i in range(3):
        for j in range(3):
            m[(a+i-1,b+j-1)]=m.get((a+i-1,b+j-1),0)+1
ans=[0]*10
for i,j in m.items():
    c,d=i
    if 1<c<h and 1<d<w:
        ans[j]+=1
ans[0]=(w-2)*(h-2)-sum(ans)
for i in ans:print(i)