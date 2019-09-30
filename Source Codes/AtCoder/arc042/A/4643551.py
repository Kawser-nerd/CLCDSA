n,m = map(int,input().split())
A = [[0,i+1] for i in range(n)]
for _ in range(m):
    a = int(input()) - 1
    A[a][0] = _ + 1
A.sort(reverse=True)
K = []
for j in range(n):
    if A[j][0] == 0:
        A = A[j::]
        A.sort()
        for i in range(len(A)):
            K.append(A[i][1])
        break
    else:
        K.append(A[j][1])
for i in K:
    print(i)