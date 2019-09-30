from operator import sub

N, K = map(int, input().split())

numA = [[0] * K for i in range(K)]
numB = [[0] * K for i in range(K)]

for i in range(N):
    x, y, c = input().split()
    x = int(x) % (2 * K)
    y = int(y) % (2 * K)

    if c == 'B':
        if (x // K == 0 and y // K == 0) or (x // K == 1 and y // K == 1):
            numA[x % K][y % K] += 1
        else:
            numB[x % K][y % K] += 1
    else:
        if (x // K == 1 and y // K == 0) or (x // K == 0 and y // K == 1):
            numA[x % K][y % K] += 1
        else:
            numB[x % K][y % K] += 1


sumXA = list(map(sum, numA))
sumYA = list(map(sum, zip(*numA)))

sumXB = list(map(sum, numB))
sumYB = list(map(sum, zip(*numB)))

sumA = sum(sumXA)
sumB = sum(sumXB)

Arr = [[0] * K for i in range(K)]
numOKA = sumA
numOKB = sumB
for x in range(K):

    tempOKA = numOKA
    tempOKB = numOKB
    for y in range(K):
        Arr[x][y] = max(tempOKA + sumB - tempOKB, sumA - tempOKA + tempOKB)
        tempOKA -= sumYA[y]
        tempOKB -= sumYB[y]

    sumYA = list(map(sub, sumYA, numA[x]))
    sumYA = list(map(sub, sumYA, numA[x]))
    numOKA -= sumXA[x]

    sumYB = list(map(sub, sumYB, numB[x]))
    sumYB = list(map(sub, sumYB, numB[x]))
    numOKB -= sumXB[x]

print(max(map(max, Arr)))