n,a,b,c,d = map(int,input().split())
for p in range(n-1):
    q = n - 1 - p
    b_min = p * c - q * d
    b_max = p * d - q * c
    if b_min <= b - a <= b_max:
        print('YES')
        exit()
print('NO')