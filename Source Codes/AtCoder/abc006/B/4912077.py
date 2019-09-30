N = int(input())
a = 0
b = 0
c = 1
d = 0
if N < 3:
    print(0)
elif N == 3:
    print(1)
else:
    for i in range(N - 3):
        d = a
        a = b
        b = c
        c = (a + b + d) % (10 ** 4 + 7)
    print(c)