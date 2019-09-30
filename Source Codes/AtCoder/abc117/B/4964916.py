N = int(input())
L = list(map(int, input().split()))
L = sorted(L)
Sum = 0
for i in range(N-1):
    Sum += L[i]
if L[N-1]<Sum:
    print("Yes")
else:
    print("No")