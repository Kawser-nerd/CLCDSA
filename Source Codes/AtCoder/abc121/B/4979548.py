N,M,C = map(int,input().rstrip().split())
B = list(map(int,input().rstrip().split()))
count = 0
sum = 0
for i in range(N):
    A = list(map(int,input().rstrip().split()))
    for k in range(M):
        sum = sum + A[k] * B[k]
    if sum + C > 0 :
        count = count + 1
    sum = 0
print(count)