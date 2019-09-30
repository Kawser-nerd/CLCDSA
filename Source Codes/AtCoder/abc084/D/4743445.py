import math
import bisect


prime = [2]

tab = [False]*100001
tab[2] = True
for i in range(3,100000+1,2):

    x = int( math.sqrt(i) )
    x += 1 if x%2 == 0 else 0

    found = False
    for p in prime:
        if x < p:
            break;

        if i % p == 0:
            found = True
            break
                
    if not found:
        prime.append(i)
        tab[i] = True

#print(prime[0:10])
#print(tab[0:10])
q = int(input())

ac = [0] * len(tab)

for i in range(1,len(ac)):
    ac[i] = ac[i-1] + (1 if tab[i] and tab[(i+1)//2] else 0)

#print(ac)
for _ in range(q):

    l, r = map(int,input().split())
    
    ans = ac[r] - ac[l-1]

    print(ans)