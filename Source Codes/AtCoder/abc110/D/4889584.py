import math
N, M = map(int, input().split())

MOD = 10 ** 9 + 7

d = []

for i in range(2, int(math.sqrt(M))+2):
    if M % i == 0:
        d.append(0)
    while M % i == 0:
        d[-1] += 1
        M //= i
if M != 1:
    d.append(1)

def comb(n, k):
    a = 1
    for i in range(k):
        a *= (n-i)
    for i in range(k):
        a //= (i+1)
    return a

answer = 1
for i in d:
    answer *= comb(i+N-1, i)
    answer %= MOD

print(answer)