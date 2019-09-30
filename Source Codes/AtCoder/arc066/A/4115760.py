mod = 10**9+7
N = int(input())
l = list(map(int, input().split()))

if N % 2 == 1:
    l.append(0)
    N -= 1
else:
    l = list(map(lambda x: x-1, l))

l = sorted(l)
i = 0
for f, s in zip(l[0::2], l[1::2]):
    if f == 2*i and s == 2*i:
        i += 1
    else:
        print(0)
        exit()

print(2**(N//2) % mod)