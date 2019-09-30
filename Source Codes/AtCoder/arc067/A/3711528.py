N = int(input())
MOD = int(1e+9) +7 
prime = [2]

for i in range(2,1001):
    for j in range(2, i-1):
        if i % j == 0:
            break
    else:
        prime.append(i)

factor = [1] * 1000

for i in range(1, N+1):
    for p in prime:
        if i == 1:
            break
        while i % p == 0:
            i /= p 
            factor[p] += 1

ans = 1
for fact in factor:
    ans *= fact
    ans %= MOD
print(int(ans))