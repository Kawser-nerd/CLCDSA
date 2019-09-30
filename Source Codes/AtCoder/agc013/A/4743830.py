N = int(input())
A = list(map(int, input().split()))

flag = False
isIncrease = True
count = 1

for i in range(len(A) - 1) :
    if not flag :
        if A[i] < A[i + 1] :
            isIncrease = True
            flag = True
        elif A[i] > A[i + 1] :
            isIncrease = False
            flag = True
    else :
        if A[i] > A[i + 1] :
            if isIncrease :
                count += 1
                flag = False
        elif A[i] < A[i + 1] :
            if not isIncrease :
                count += 1
                flag = False

print(count)