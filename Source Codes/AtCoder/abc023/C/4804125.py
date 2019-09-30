from collections import Counter

r,c,k = map(int,input().split())
n = int(input())
RC = [list(map(int,input().split())) for i in range(n)]

rows = [0]*r
colums = [0]*c
for i,j in RC:
    rows[i-1] += 1
    colums[j-1] += 1

R = Counter(rows)
C = Counter(colums)
res = 0
for i in R.keys():
    res += R[i]*C[k-i]
for i,j in RC:
    if rows[i-1]+colums[j-1] == k:
        res -= 1
    if rows[i-1]+colums[j-1] == k+1:
        res += 1

print(res)