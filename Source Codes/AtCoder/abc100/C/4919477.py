N = int(input())
A = list(map(int, input().split()))
two_num = 0
for i in range(len(A)):
    while A[i] % 2 == 0:
        two_num += 1
        A[i] = A[i] / 2
print(two_num)