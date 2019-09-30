N = int(input())
A = [int(_) for _ in input().split()]
A = sorted(A)[::-1]
print(sum(A[::2]))