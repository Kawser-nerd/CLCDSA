b=[0]*26
a=input()
n=len(a)
for i in range(n):
    b[ord(a[i])-ord("a")]+=1
print(n*(n-1)//2-sum([i*(i-1)//2 for i in b])+1)