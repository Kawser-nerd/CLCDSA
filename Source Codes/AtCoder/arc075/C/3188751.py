def mergecount(A):
    cnt = 0
    n = len(A)
    if n>1:
        A1 = A[:n>>1]
        A2 = A[n>>1:]
        cnt += mergecount(A1)
        cnt += mergecount(A2)
        i1=0
        i2=0
        for i in range(n):
            if i2 == len(A2):
                A[i] = A1[i1]
                i1 += 1
            elif i1 == len(A1):
                A[i] = A2[i2]
                i2 += 1
            elif A1[i1] <= A2[i2]:
                A[i] = A1[i1]
                i1 += 1
            else:
                A[i] = A2[i2]
                i2 += 1
                cnt += n//2 - i1
    return cnt

N, K = map(int, input().split())
A = [int(input()) for i in range(N)]
Ak = [a-K for a in A]
Aks = [0]
t = 0
for ak in Ak:
    t += ak
    Aks.append(t)
print(N*(N+1)//2 - mergecount(Aks))