s=input()
c=[0,0]
d=[]
b=0
for i in range(len(s)-1,-1,-1):
    if s[i]=="M":
        d.append(c[0]-c[1])
        b+=1
    elif s[i]=="+":
        c[0]+=1
    else:
        c[1]+=1
d.sort()
print(sum(d[b//2:])-sum(d[:b//2]))