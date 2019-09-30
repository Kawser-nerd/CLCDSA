a,b=map(int,input().split())
l=[]
for i in range(a,b+1):
    l.append(str(i))
ctr=0
for i in range(len(l)):
    if l[i][0]==l[i][4] and l[i][1]==l[i][3]:
        ctr+=1
print(ctr)