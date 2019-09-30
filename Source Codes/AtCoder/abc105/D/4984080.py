from collections import Counter
from math import factorial
# M?????????????????????????????
N , M = map(int, input().split())
an = list(map(int,input().split()))
ca = [0] * N
ca[0] = an[0] % M
ans = 0
for i in range(N):
    if i > 0:
        ca[i] = (ca[i-1] + an[i]) % M
    if ca[i] % M == 0:
        ans += 1
# M????????????Counter????????
c = list(Counter(ca).items())
for ci in c:
    if ci[1] >= 2:
        ans += factorial(ci[1]) // (factorial(2) * factorial(ci[1]-2))
print(ans)