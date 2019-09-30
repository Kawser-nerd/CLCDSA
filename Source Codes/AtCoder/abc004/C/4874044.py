C = [1,2,3,4,5,6]
N = int(input())
if N >= 30:
    N = N%30
for i in range(N):
    i = i%5
    C[i],C[i+1] = C[i+1],C[i]

print(*C,sep='')