N = int(input())
D = [[0 for i in range(N)] for j in range(N)]

for i in range(N):

    D[i] = list(map(int,input().split()))

Q = int(input())
P = [0] * Q

for i in range(Q):

    P[i] = int(input())

answer = [[0 for i in range(1)] for j in range((N**2)+1)]
count = [1] * (N**2+1)
itika = [[0 for i in range(N)] for j in range((N**2)+1)]

for i in range(N+1):

    for j in range(N+1):

        for k in range(N-i+1):

            if i >= 1 and j >= 1:
                
                if k == 0:
                    
                    itika[((i-1)*N)+j][k] = D[j-1][i-1]

                else:

                    itika[((i-1)*N)+j][k] = itika[((i-1)*N)+j][k-1] + D[j-1][i-1+k]


for i in range(N+1):

    for j in range(N+1):

        for k in range(N-i+2):

            for l in range(N-j+2):

                if i >= 1 and j >= 1 and k >= 1 and l >= 1:
                    
                    if l == 1:
                        
                        answer[k*l].append(itika[((i-1)*N)+j][k-1])
                        count[k*l] += 1

                    else:

                        answer[k*l].append(answer[k*l-k][count[k*l-k]-1] + itika[((i-1)*N)+j+l-1][k-1])
                        count[k*l] += 1

DarkFlameMaster = [0] * ((N**2)+1)

for i in range((N**2)+1):

    if i >= 1:

        DarkFlameMaster[i] = max([max(answer[i]),DarkFlameMaster[i-1]])

       


for i in range(Q):

    print(DarkFlameMaster[P[i]])