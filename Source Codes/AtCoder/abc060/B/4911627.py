A,B,C = map(int,input().split())

amaris = []

flag = False
count = 1
tmp = A
while True:
    amari = tmp % B
    if C == amari:
        flag = True
        break
    if amari in amaris:
        break
    amaris.append(amari)
    count += 1
    tmp = A * count

if flag:
    print("YES")
else:
    print("NO")