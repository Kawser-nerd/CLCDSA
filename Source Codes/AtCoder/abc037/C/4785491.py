n, k = (int(i) for i in input().split())
a = [int(i) for i in input().split()]

sub = sum(a[:k])
res = sub

for i in range(n-k):
    sub += a[i+k] - a[i]
    res += sub

print(res)