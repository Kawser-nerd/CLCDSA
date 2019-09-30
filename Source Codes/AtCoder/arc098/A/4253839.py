n=int(input())
s=list(input())
p=[0,0]
l=[s.count("E"),s.count("W")]
t=[]
for i in range(n):
    if s[i]=="E":
        t.append(l[0]+p[1]-1)
        l[0]-=1
        p[0]+=1
    else:
        t.append(l[0]+p[1])
        l[1]-=1
        p[1]+=1
print(min(t))