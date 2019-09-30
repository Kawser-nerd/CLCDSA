n,*a=map(int,open(0).read().split());b={v:k for(k,v)in enumerate(sorted(set(a)))}
for i in a:
    print(b[i])