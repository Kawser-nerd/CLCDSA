import math
import bisect


prime = [2,3,5,7,11,13,17,19,23]

tab = [False]*100001
tab[2] = True

for i in range(prime[-1]+2,100000+1,2):

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


#print(prime[10:100])
for p in prime:
    tab[p] = True

#print(tab[100:150])
q = int(input())

ac = [0] * len(tab)

for i in range(3,len(ac),2):
    ac[i-1] = ac[i-2]
    ac[i] = ac[i-1] + (1 if tab[i] and tab[(i+1)//2] else 0)

#print(ac)
for _ in range(q):

    l, r = map(int,input().split())
   
    
    ans = ac[r] - ac[l-1]

    print(ans)