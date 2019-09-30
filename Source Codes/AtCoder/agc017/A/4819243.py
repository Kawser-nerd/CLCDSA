n, p = map(int, input().split())
a = list(map(int, input().split()))
m = [0, 0]
for i in range(n):
    m[a[i] % 2] += 1
if m[1] == 0 and p == 1:
    print(0)
else:
    print(2**m[0] * 2**(m[1]-1) if m[1] > 0 else 2**m[0])