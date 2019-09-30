r, c, k = map(int, input().split())
n = int(input())

RC = [[int(i) for i in input().split()] for i in range(n)]
    
R = [0] * r
C = [0] * c
for i in range(n):
    R[RC[i][0] - 1] += 1
    C[RC[i][1] - 1] += 1
    #??????????
        
R2 = [0] * (n + 1)
for i in range(r):
    R2[R[i]] += 1
    #???????????

C2 = [0] * (n + 1)
for i in range(c):
    C2[C[i]] += 1
    #???????????

cnt = 0
for i in range(n + 1):
    j = k - i
    cnt += R2[i] * C2[j]
            
for i in range(n):
    if R[RC[i][0] - 1] + C[RC[i][1] - 1] == k:
        cnt -= 1
    if R[RC[i][0] - 1] + C[RC[i][1] - 1] == k + 1:
        cnt += 1
            
print(cnt)