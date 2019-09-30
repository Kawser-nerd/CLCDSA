l=list(map(int,open(0)))
s=sorted(l)[::-1]
for i in l:
    print(s.index(i)+1)