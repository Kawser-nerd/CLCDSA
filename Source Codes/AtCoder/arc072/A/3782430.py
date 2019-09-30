_ = int(input())
A = list(map(int, input().split()))

ret = float('inf')

sign = 1
s = 0
k = 0
for a in A:
    if sign * (s + a) > 0:
        s += a
    else:
        k += abs(s + a) + 1
        s = sign
    sign *= -1
ret = min(ret, k)

sign = -1
s = 0
k = 0
for a in A:
    if sign * (s + a) > 0:
        s += a
    else:
        k += abs(s + a) + 1
        s = sign
    sign *= -1

ret = min(ret, k)


print(ret)