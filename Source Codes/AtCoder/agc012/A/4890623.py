N = int(input())
A = list(map(int,input().split()))
A.sort(reverse=True)
print(sum(A[1::2][:N]))