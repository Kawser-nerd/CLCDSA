A = list(map(int, input().split()))
B = list(map(int, input().split()))

res = 0
for i in range(7):
    res += max(A[i], B[i])
    
print(res)