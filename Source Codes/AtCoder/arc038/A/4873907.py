N = int(input())
A = sorted([int(i) for i in input().split()], reverse = True)
print(sum(A[::2]))