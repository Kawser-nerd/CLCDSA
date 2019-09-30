n,m = map(int,input().split())
A = [[0,i+1] for i in range(n)]
for i in range(m):
    a = int(input()) - 1
    A[a][0] = i + 1
A.sort(reverse=True)
K = []
for i in range(n):
    if A[i][0] == 0:
        A = A[i::]
        A.sort()
        for j in range(len(A)):
            K.append(A[j][1])
        break
    else:
        K.append(A[i][1])
for i in K:
    print(i)