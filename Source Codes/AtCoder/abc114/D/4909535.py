N = int(input())

# 1 75, 3 25, 5 15 

def find_primes(n):
    nums=list(range(2,n+1))
    primes = []
    while nums:
        p = nums[0]
        primes.append(p)
        for _ in range(6):
            nums = [n if n%p else n//p for n in nums]
        nums = [n for n in nums if n!=1]
    return primes
assert(find_primes(30)[9]==29)

#primes = find_primes(100)

def primes_of_factor(n):
    nums=list(range(1,n+1))
    primes = find_primes(n)
    ret = {p:0 for p in primes}
    for p in primes:
        s = sum([n%p==0 for n in nums])
        ret[p] += s
        while s:
            nums = [n//p if n%p==0 else n for n in nums]
            s = sum([n%p==0 for n in nums])
            ret[p] += s
    return ret
assert(primes_of_factor(25)[5]==6)

primes = primes_of_factor(N)

answer = len([v for v in primes.values() if v>=74])

from itertools import permutations

for P,Q in permutations(primes.items(), 2):
    if P[1]>=24 and Q[1]>=2:
        answer +=1
    if P[1]>=14 and Q[1]>=4:
        answer +=1

for P,Q,R in permutations(primes.items(), 3):
    if P[1]>=2 and Q[1]>=4 and R[1]>=4:
        if Q[0]>R[0]:
            answer +=1

print(answer)