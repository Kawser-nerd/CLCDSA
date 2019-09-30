n = int(input())
A = list(map(int,input().split()))
takahashi = []
for i in range(n):
    aoki = []
    for j in range(n):
        if i == j:
            aoki.append(-10**9+7)
        elif i < j:
            aoki.append(sum(A[i+1:j+1:2]))
        else:
            aoki.append(sum(A[j+1:i+1:2]))
    m = aoki.index(max(aoki))
    takahashi.append(sum(A[min(i,m):max(i+1,m+1)])-aoki[m])

print(max(takahashi))