a,b=map(int,input().split())
c=[False]*41
c[a]=True
d=0
while not c[b]:
    k=c[:]
    d+=1
    for i in range(41):
        if k[i]:
            if i-1!=-1:
                c[i-1]=True
                if i-5>-1:
                    c[i-5]=True
                    if i-10>-1:
                        c[i-10]=True
            if i+1<41:
                c[i+1]=True
                if i+5<41:
                    c[i+5]=True
                    if i+10<41:
                        c[i+10]=True
print(d)