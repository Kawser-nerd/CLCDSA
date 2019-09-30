N = int(input())
P = [list(map(int, input().split())) for i in range(N)]
B = int(input())
ans = 0
for i in range(N):
    a, l = P[i]
    la = len(str(a))
    k = la; b = a
    while l:
        if l & 1:
            ans = (ans * pow(10, k, B) + b) % B
        b = (b * pow(10, k, B) + b) % B
        k *= 2
        l >>= 1
print(ans)