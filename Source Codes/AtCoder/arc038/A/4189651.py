N = int(input())
A = [int(i) for i in input().split()]
print(sum(sorted(A, reverse=True)[0::2]))