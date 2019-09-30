n, k = list(map(int, input().split()))

sub = 0
for i in range(1, n+1):
    s = n//i
    sub += s*(min(i, k))
    sub += min(n%i, max(0, k-1))
print(n**2 - sub)