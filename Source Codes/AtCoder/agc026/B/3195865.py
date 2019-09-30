from fractions import gcd
n = int(input())
A = [list(map(int, input().split())) for _ in range(n)]
for i in range(n):
    a,b,c,d = A[i]
    g = gcd(b,d)
    if a < b or b > d or b-g+(a%g)>c:
        print('No')
    else:
        print('Yes')