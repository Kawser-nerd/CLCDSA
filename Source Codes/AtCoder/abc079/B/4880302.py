N = int(input())

if N==0:
    print(2)
elif N == 1:
    print(1)
else:
    a = 2
    b = 1
    for i in range(2, N+1):
        c = b + a
        b, a = c, b
    print(c)