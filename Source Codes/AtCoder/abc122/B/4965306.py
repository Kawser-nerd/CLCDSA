S = (input())
k=0
j=0
for  chr in S:
    if (chr=='A')or(chr=='C')or(chr=='G')or(chr=='T'):
        j=j+1
    else:
        if k<j:
            k=j
        j=0
if k<j:
    k=j
print(k)