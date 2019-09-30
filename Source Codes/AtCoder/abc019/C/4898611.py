N = int(input())
A = list(map(int, input().split()))

B = []

for i in range(N):
    while True:
        if A[i]%2==0:
            A[i] = A[i]//2
        else:
            B.append(A[i])
            break

C = set(B)

print(len(C))