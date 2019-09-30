h,w=map(int,input().split())
s=[list(map(int,input().split()))for i in range(h)]
p=True
q=[0,0]
d=[]
for i in range(h):
    if i%2==0:
        for j in range(w):
            if p:
                if s[i][j]%2==1:
                    q=[i,j]
                    p=False
            else:
                d.append([q[0]+1,q[1]+1,i+1,j+1])
                q=[i,j]
                if s[i][j]%2==1:
                    p=True
    else:
        for j in range(w-1,-1,-1):
            if p:
                if s[i][j]%2==1:
                    q=[i,j]
                    p=False
            else:
                d.append([q[0]+1,q[1]+1,i+1,j+1])
                q=[i,j]
                if s[i][j]%2==1:
                    p=True
print(len(d))
for i in d:
    print(i[0],i[1],i[2],i[3])