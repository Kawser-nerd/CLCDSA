n, a, b, c, d = map(int, input().split())
n -= 1
k = abs(b-a)
if k > n*d:
    print("NO")
elif k >= n*c:
    print("YES")
else:
    i = -(-(n*c-k)//(2*c))
    haba = k - (n-2*i)*c
    if haba <= (d-c)*(n-i):
        print("YES")
    else:
        j = i-1
        haba = (n-2*j)*c - k
        if haba <= (d-c)*j:
            print("YES")
        else:
            print("NO")