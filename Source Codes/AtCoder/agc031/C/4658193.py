def makep(n, l, mask):
    a = l[0] & mask
    b = l[-1] & mask
    ll = len(l)
    diff = a ^ b
    for i in range(n):
        if(((diff >> i) & 1) != 0):
            diff = 1 << i
            break

#    print("a = {}, b = {}, mask = {}, ll = {}, diff = {}".format(a, b, mask, ll, diff))

    for i, elem in enumerate(l[1:-1], 1):
        if(i < ll // 2):
            l[i] = (l[i] & ~diff) | (a & diff)
        else:
            l[i] = (l[i] & ~diff) | (b & diff)

#    print("l = {}".format(l))

    nextbit = mask & ~diff
    if(0 != nextbit):
        for i in range(n):
            if(((nextbit >> i) & 1) != 0):
                nextbit = 1 << i
                break
        l[ll // 2 - 1] = (l[ll // 2 - 1] | (a & ~diff)) ^ nextbit
        l[ll // 2 - 0] = (l[ll // 2 - 0] | (a & ~diff)) ^ nextbit

#        print("nextbit = {}, ll//2 = {}, l = {}".format(nextbit, ll//2, l))

    if(ll > 2):
        l[:ll // 2] = makep(n, l[:ll // 2], mask & ~diff)
        l[ll // 2:] = makep(n, l[ll // 2:], mask & ~diff)
    return(l)

N, A, B = map(int, input().split())

A1num = "{:b}".format(A).count("1")
B1num = "{:b}".format(B).count("1")

if((A1num % 2) == (B1num % 2)):
    print("NO")
    exit()

print("YES")

p = [0] * (2 ** N)
p[0] = A
p[-1] = B
p = makep(N, p, 2 ** N - 1)

#for i in p:
#    print("{:08b}".format(i))

print(" ".join(map(str, p)))