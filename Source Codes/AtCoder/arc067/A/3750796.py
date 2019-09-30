from math import factorial

n = factorial(int(input()))
cnt = 2
k = 1
ans = 1

while n != 1:
    if n % cnt == 0:
        n //= cnt
        k = k + 1
    else:
        ans = ans * k
        k = 1
        cnt += 1
anw = (ans * k) % (10**9 + 7)
print(anw)