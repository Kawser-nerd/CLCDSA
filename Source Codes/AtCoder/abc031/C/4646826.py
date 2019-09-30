n = int(input())
A = list(map(int,input().split()))
t = []
for i in range(n):
    a = []
    for j in range(n):
        if i == j:
            a.append(-10**9+7)
        else:
            a.append(sum(A[min(i+1,j+1):max(i+1,j+1):2]))
    m = a.index(max(a))
    t.append(sum(A[min(i,m):max(i+1,m+1)])-a[m])
print(max(t))