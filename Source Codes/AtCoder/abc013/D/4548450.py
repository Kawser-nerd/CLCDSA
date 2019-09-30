N,M,D = map(int,input().split())
A = list(map(int,input().split()))
B = [[] for i in range(N)]
to = []
answer = []
x = 0
check = 0

for i in range(N):

    to.append(i+1)

for k in range(M):

    j = (M-1-k)
    to[A[j]-1],to[A[j]] = to[A[j]],to[A[j]-1]

while check == 0:

    if D // (2**x) == 0:

        check = 1

    else:

        x += 1

for i in range(x):

    if i == 0:
        
        for j in range(N):

            B[j].append(to[j])

    else:

        for j in range(N):

            B[j].append(B[B[j][i-1]-1][i-1])

for i in range(N):

    k = i+1

    for j in range(x):

        if bin(D)[j+2] == '1':

            k = B[k-1][x-1-j]

    print(k)