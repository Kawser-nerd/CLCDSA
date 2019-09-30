L = int(input())
b = []
a = 0
an = 0
for i in range(L):
    b.append(int(input()))
    if i != L-1:
        an = an ^ b[i]
    else:
        if an != b[i] ^ 0:
            print(-1)

        else:
            print(0)
            for i in range(L-1):
                a = a ^ b[i]
                print(a)