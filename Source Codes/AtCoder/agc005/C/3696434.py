from collections import Counter as C

N = int(input())
A = [int(a) for a in input().split()]

B = C(A)
ma = max(B)
mi = min(B)

if (ma==mi*2 and B[ma]>=2 and B[mi]==1) or (ma==mi*2-1 and B[ma]>=2 and B[mi]==2):
    for i in range(mi+1,ma):
        if B[i] < 2:
            print("Impossible")
            break
    else:
        print("Possible")
else:
    print("Impossible")