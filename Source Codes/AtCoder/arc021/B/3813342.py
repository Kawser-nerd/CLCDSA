L = int(input())
B = [int(input()) for _ in range(L)]

a = [0]*(L+1)
for i in range(L):
    a[i+1] = a[i]^B[i]
if a[0] == a[-1]:
    for a_i in a[:-1]:
        print(a_i)
else:
    print(-1)