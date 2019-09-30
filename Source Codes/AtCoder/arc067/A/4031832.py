from collections import Counter

def trial_division(n):
    a = []  
    while n % 2 == 0:
        a.append(2)
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            a.append(f)
            n //= f
        else:
            f += 2   
    if n != 1: a.append(n)
    #Only odd number is possible
    return a

N = int(input())
D = {}
for i in range(1,N+1) :
    C = dict(Counter(trial_division(i)))
    for j in C :
        if j not in D :
            D[j] = C[j]
        else :
            D[j] += C[j]
ans = 1
for i in D.values() :
    i %= 10**9+7
    ans *= i+1
    ans %= 10**9+7
print(ans)
#print(D)