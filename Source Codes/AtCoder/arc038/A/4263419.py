import math
N = int(input())
A = input().split(" ")
A = [int(i) for i in A]
A = sorted(A,reverse = True)
listA = []
listB = []
c = 0
for i in range(math.ceil(N/2)):
    listA.append(A[i+c])
    if N % 2 != 0 and i+c+1 > N-1:
        pass
    else:
        listB.append(A[i+c+1])
    c += 1
#print(listA,listB)
print(sum(listA))