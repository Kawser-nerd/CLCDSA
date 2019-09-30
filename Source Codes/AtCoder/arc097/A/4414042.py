s=input()
K=int(input())
l=len(s)
d=[[s[i],l-i] for i in range(len(s))]
d=sorted(d)
h=dict()
ans=0
ca=d[0][0]   

for i in d:
    if(i[0]!=i[0][0]):
        break
    z=min(i[1]+1,6)
    for j in range(1,z):
        if(s[l-i[1]:l-i[1]+j] not in h):
            ans+=1
            h.update({s[l-i[1]:l-i[1]+j]:1})
        else:
            pass


h=sorted(h)
print(h[K-1])