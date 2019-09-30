h,w=map(int,input().split())
s=[["#"]*(w+2)]+[["#"]+list(input())+["#"]for i in range(h)]+[["#"]*(w+2)]
p=[[1,1]]
d=0
for i in range(1,h+1):
    for j in range(1,w+1):
        if s[i][j]==".":
            d+=1
s[1][1]="#"
k=0
while [h,w] not in p:
    k+=1
    g=[]
    for i in range(len(p)):
        x,y=p[i][0],p[i][1]
        if s[x-1][y]==".":
            s[x-1][y]="Q"
            g.append([x-1,y])
        if s[x+1][y]==".":
            s[x+1][y]="Q"
            g.append([x+1,y])
        if s[x][y+1]==".":
            s[x][y+1]="Q"
            g.append([x,y+1])
        if s[x][y-1]==".":
            s[x][y-1]="Q"
            g.append([x,y-1])
    else:
        p=g
        if len(p)==0:
            print(-1)
            break
else:
    print(d-k-1)