def multiset(a,b): #list?ab 
    x,y=list(set(a)&set(b)),[]
    for s in x:
        for t in range(min([a.count(s),b.count(s)])):
            y.append(s)
    return y
map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
print(len(multiset(a,b)))