n = int(input())
k = int(input())
x = int(input())
y = int(input())

if n <= k:
    print(x*n)

else:
    print(x*k+y*(n-k))