A, B = list(map(int, input().split()))
c = []
c.append(A % 4 // 2 ^ (B + 1) % 4 // 2)

keta = 2
while(B // keta != 0):
    if A // keta % 2 == 0:
        a = 0
    else:
        a = A % keta
    if B // keta % 2 == 0:
        b = 0
    else:
        b = B % keta
        b += 1
    c.append((b - a) % 2)
    keta = keta<<1
ans = 0

for i in range(len(c) - 1, -1, -1):
    ans = ans<<1
    ans ^= c[i]
print(ans)