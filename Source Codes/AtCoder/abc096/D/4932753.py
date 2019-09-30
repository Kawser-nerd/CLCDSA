N = int(input())

primes = [2,3,5,7]
ans = []
for n in range(11,55555+1):
    for p in primes:
        if n % p == 0:
            break
    else:
        primes.append(n)
        if n%5==1:
            ans.append(n)
            if len(ans) >= N:
                break
print(" ".join(map(str,ans)))