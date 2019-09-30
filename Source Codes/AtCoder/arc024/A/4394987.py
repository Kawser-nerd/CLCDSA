L, R = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

tmp1 = [0 for i in range(100)]
tmp2 = [0 for i in range(100)]

for i in range(L):
    tmp1[A[i] - 1] += 1
    
for i in range(R):
    tmp2[B[i] - 1] += 1
    

res = 0
for i in range(100):
    res += min(tmp1[i], tmp2[i])
    
print(res)