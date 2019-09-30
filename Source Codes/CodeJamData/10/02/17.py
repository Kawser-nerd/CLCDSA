def nwd (a, b) :
     if b==0 :
         return a;
     return nwd (b,a%b);

z=int(raw_input());
for q in range (z) :
    s=raw_input().split()
    n = int(s[0])
    tab=[]
    for i in range (n) :
        tab.append(int(s[i+1]))
    tab.sort()
    d=tab[1]-tab[0];
    for i in range (n-2) :
        d = nwd(d,tab[i+2]-tab[i+1]);
    res = (d-tab[0]%d)%d;
    print "Case #"+str(q+1)+": "+str(res);       
