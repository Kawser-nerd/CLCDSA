n = int(input())
a = [[0]*(n+1) for i in range(n+1)]
np = (n//2)*2

for i in range(0,np//2):
    a[i+1][np-i] = -1

print(int(n*(n-1)/2-(n//2)))

for i in range(1,n+1):
    for j in range(i+1,n+1):
        if a[i][j] == -1:
            continue
        else:
            print(i,j)