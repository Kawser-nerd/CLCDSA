A,B = map(int,input().split())
pA = [int(c) for c in list(str(A))]
if pA[0] == 9:
    if pA[1] == 9:
        if pA[2] == 9:
            pass
        else:
            pA[2] = 9
    else:
        pA[1] = 9
else:pA[0] = 9
ppA = pA[0]*100+pA[1]*10+pA[2]

pB = [int(c) for c in list(str(B))]
if pB[0] == 1:
    if pB[1] > 0:
        pB[1] = 0 
    else:
        if pB[2] > 0:
            pB[2] = 0
else:
    pB[0] = 1
ppB = pB[0]*100+pB[1]*10+pB[2]
print(max(A-B,ppA-B,A-ppB))