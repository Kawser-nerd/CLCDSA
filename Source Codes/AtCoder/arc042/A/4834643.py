n,m,*a=map(int,open(0).read().split())
b=set()
for i in a[::-1]:
    if i not in b:
        b.add(i)
        print(i)
for i in range(1,n+1):
    if i not in b:
        print(i)