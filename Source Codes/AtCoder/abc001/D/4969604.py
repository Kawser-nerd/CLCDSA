n = int(input())
a = [0] * 482
for i in range(n):
    b,c = map(int, input().split("-"))
    b -= b%5
    if c%5 != 0:
        c += 5-(c%5)
        if c % 100 == 60:
            c += 40
    b //= 5
    c //= 5
    a[b] += 1
    a[c] -= 1
ren = False
tmp = 0
for i in range(len(a)):
    tmp += a[i]
    if tmp != 0:
        if ren == False:
            s = str(i*5).zfill(4) + "-"
            print(s, end = "")
            ren = True
    elif tmp == 0:
        if ren:
            ren = False
            s = str(i*5).zfill(4)
            print(s)