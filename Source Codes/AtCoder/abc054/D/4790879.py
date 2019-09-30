n,a,b=map(int,input().split())
d=[[0]*401 for i in range(401)]
h=[]
for i in range(n):
    s=[]
    c=d[:]
    p,q,r=map(int,input().split())
    if d[p][q]!=0:
        d[p][q]=min(r,c[p][q])
    else:
        s.append([p,q])
        d[p][q]=r
    h=sorted(h,key=lambda x:x[1]+x[0])
    for j in range(len(h)-1,-1,-1):
        if h[j][0]+p<401 and h[j][1]+q<401:
            if c[h[j][0]+p][h[j][1]+q]!=0:
                d[h[j][0]+p][h[j][1]+q]=min(r+c[h[j][0]][h[j][1]],d[h[j][0]+p][h[j][1]+q])
            else:
                s.append([h[j][0]+p,h[j][1]+q])
                d[h[j][0]+p][h[j][1]+q]=r+c[h[j][0]][h[j][1]]
    else:
        h+=s
else:
    c=float("inf")
    k=1
    while a*k<401 and b*k<401:
        if d[a*k][b*k]!=0:
            c=min(c,d[a*k][b*k])
        k+=1
    else:
        if c==float("inf"):
            print(-1)
        else:
            print(c)