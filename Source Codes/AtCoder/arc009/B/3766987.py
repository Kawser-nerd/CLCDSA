L=list(map(str,input().split()))
A=["a","b","c","d","e","f","g","h","i","j"]
a=["0","1","2","3","4","5","6","7","8","9"]

c=[]
N=int(input())
for i in range(N):
    s=input()
    s1=""
    for j in range(len(s)):
        for k in range(len(L)):
            if s[j]==L[k]:
                s1+=a[k]
    c.append(int(s1))
c.sort()
#print(c)
for x in range(N):
    c[x]=str(c[x])
    C=""
    for y in range(len(c[x])):
        for z in range(len(a)):
            if c[x][y]==a[z]:
                C+=L[z]
    print(C)