s=set(range(10))
n,k,*a=map(int,open(0).read().split())
a=s-set(a) #???????
for t in range(n,100000):
    if set(list(map(int,list(str(t)))))<=a:
        print(t)
        break