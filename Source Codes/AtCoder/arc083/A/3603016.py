A, B, C, D, E, F=map(int, input().split())
wans=0
sans=0
for i in range(31):
    w=100*A*i
    s=0
    if s+w>F:
        break
    for j in range(31):
        w=100*A*i+100*B*j
        s=0
        if s+w>F:
            break
        for k in range(3001):
            w=100*A*i+100*B*j
            s=C*k
            if s+w>F:
                break
            for l in range(3001):
                w=100*A*i+100*B*j
                s=C*k+D*l
                if s+w>F:
                    break
                if w!=0 and s*(100+E)<=(s+w)*E and sans*(s+w)<=s*(sans+wans) and w+s<=F:
                    sans=s
                    wans=w
                #print(sans,sans+wans)
print(sans+wans,sans)