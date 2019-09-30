n,m = map(int, input().split())
if n == 1 or m == 1:
    if n == 1 and m == 1:
        print(1)
    else:
        print(max(n,m)-2)
else:
    print((m-2)*(n-2))