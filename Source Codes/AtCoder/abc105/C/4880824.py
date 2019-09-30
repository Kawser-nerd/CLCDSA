N = int(input())
a = ''
n = 0
while N != 0:
    b = '0' if N % (2**(n + 1)) == 0 else '1'
    a += b
    N -= ((-2)**n) * int(b)
    n += 1
print(a[::-1] if a else 0)