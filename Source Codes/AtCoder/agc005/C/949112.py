N = int(input())
A = list(map(int, input().split()))
A.sort()
maxv1 = A[-1]
maxv2 = A[-2]
if maxv1 != maxv2:
    print("Impossible")
    exit()

K = maxv1
if K % 2 == 0:
    for i in range(K // 2):
        for j in range(2):
            if K - i in A:
                A.remove(K - i)
            else:
                print("Impossible")
                exit()
    if K // 2 in A:
        A.remove(K // 2)
    else:
        print("Impossible")
        exit()
else:
    for i in range(K // 2 + 1):
        for j in range(2):
            if K - i in A:
                A.remove(K - i)
            else:
                print("Impossible")
                exit()
if len(A) == 0:
    print("Possible")
    exit()
else:
    for a in A:
        if K % 2 == 0:
            if a < K // 2 + 1:
                print("Impossible")
                exit()
        else:
            if a < (K + 1) // 2 + 1:
                print("Impossible")
                exit()
    print("Possible")