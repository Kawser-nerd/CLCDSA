N=int(input())
p=list(map(int,input().split()))
P=[]
for j in range(len(p)):
    P.append([p[j],j])
P.sort()
a=[]
b=[]

for i in range(1,len(p)+1):
    a.append(str(i*20001+P[i-1][1]))
    b.append(str((len(p)+1-i)*20001+P[i-1][1]))
    
print(" ".join(a))
print(" ".join(b))