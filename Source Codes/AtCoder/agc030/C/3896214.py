k = int(input())

mx = 500

if k <= mx:
    print(k)
    for i in range(1, k + 1):
        print(*([i] * k), sep=" ")
else:
    cv = [[0 for i in range(mx)] for j in range(mx)]
    for i in range(mx):
        for j in range(mx):
            cv[i][(i + j) % mx] = j + 1
            if i % 2 == 1 and j + 1 + mx <= k:
                cv[i][(i + j) % mx] += mx
    
    print(mx)
    for i in range(mx):
        print(*cv[i], sep = " ")