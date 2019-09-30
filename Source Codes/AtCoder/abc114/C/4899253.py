import itertools
n=int(input())

keta=len(str(n))
hako=[]
for i in range(3,keta+1):
    for c in list(itertools.product(["7","5","3"],repeat=i)):
        if len(set(c))==3:
            a=int("".join(c))
            hako.append(a)
if n in hako:
    hako.sort()
    k=hako.index(n)
    b=hako[:k]
    print(len(b)+1) 
else:
    hako.append(n)
    hako.sort()
    k=hako.index(n)
    b=hako[:k]
    print(int(len(b)))