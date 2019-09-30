from bisect import bisect as b;n=int(input());l=[]
for d in range(n):
    i=int(input())
    a=b(l,i)
    if a==len(l):
        l.append(i)
    else:
        l[a]=i
print(n-len(l))