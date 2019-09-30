T = int(input())
N = int(input())
A = list(map(int,input().split()))
M = int(input())
B = list(map(int,input().split()))

for i in range(N):
        if A[i] <= B[0] and B[0] <= A[i] + T:
            del(B[0])
        if len(B) == 0:
            break

print('yes' if len(B) == 0 else 'no')