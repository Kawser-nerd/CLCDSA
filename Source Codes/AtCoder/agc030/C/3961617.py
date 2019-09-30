from math import sqrt, ceil
K = int(input())
 
if K <= 500:
    print(K)
    for i in range(K):
        Cout = [i+1 for n in range(K)]
        print(" ".join(map(str, Cout)))
else:
    lim = int(sqrt(K))
    for i in range(2, lim+1):
        if K % (i**2) == 0:
            print(K//i)
            for n in range(K//i):
                Cout = [i * n + (mod % i) + 1 for mod in range(K//i)]
                print(" ".join(map(str, Cout)))
            break
    else:
        n = 2 * ceil(K/4)
        print(n)
        for raw in range(n):
            if raw % 2 == 0:
                Cout = [(raw + c) % n + 1 for c in range(n)]
            else:
                Cout = [n + 1 + (raw + c) % n for c in range(n)]
                for i in range(n):
                    if Cout[i] > K: Cout[i] -= n
            print(" ".join(map(str, Cout)))