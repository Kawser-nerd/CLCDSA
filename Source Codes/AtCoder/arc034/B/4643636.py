n=int(input())
d=[]
for i in range(max(0,n-153),n+1):
    if n==i+sum([int(x) for x in list(str(i))]):
        d.append(i)
print(len(d))
for i in d:
    print(i)