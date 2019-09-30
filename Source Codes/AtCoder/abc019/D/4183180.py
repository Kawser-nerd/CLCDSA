n = int(input())

a = 1
b = 2
c = 3
ma = 1
for i in range(2, n+1):
    print("?", a, i)
    t = int(input())
    if t >= ma:
        ma=t
        b=i

ma=0
for i in range(1, n+1):
    if b == i:
        continue
    print("?", b, i)
    t = int(input())
    if t >= ma:
        ma=t
        c=i

print("!", ma)