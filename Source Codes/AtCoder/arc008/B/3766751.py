N,M=map(int,input().split())
n=input()
k=input()

A=["A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"]
a=[0 for i in range(26)]

for i in range(len(n)):
    for j in range(26):
        if n[i]==A[j]:
            a[j]+=1
#print(a)

b=[0 for i in range(26)]
for l in range(len(k)):
    for m in range(26):
        if k[l]==A[m]:
            b[m]+=1
#print(b)

for x in range(1,51):
    cnt=0
    for y in range(26):
        if a[y]<=b[y]*x:
            cnt+=1
        else:
            break
    if cnt==26:
        print(x)
        exit()
print(-1)