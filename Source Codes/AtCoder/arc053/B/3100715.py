S=input()
c=[0 for i in range(26)]
for i in S:
    c[ord(i)-97]+=1
L=0
for i in range(26):
    if c[i]%2==1:
        L+=1
        c[i]-=c[i]%2
M=sum(c)//2
T=[1 for i in range(L)]
if L==0:
    print(len(S))
    exit()
for k in range(M):
    T[k%L]+=2
print(min(T))