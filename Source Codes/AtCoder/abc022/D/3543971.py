N = int(input())
A = [list(map(int,input().split())) for i in range(N)]
B = [list(map(int,input().split())) for i in range(N)]

Ag = [0,0]
Bg = [0,0]

for i in range(N):
    Ag[0] += A[i][0]
    Ag[1] += A[i][1]
    Bg[0] += B[i][0]
    Bg[1] += B[i][1]

Ag[0] /= N
Ag[1] /= N
Bg[0] /= N
Bg[1] /= N

dA = [0]*N
dB = [0]*N

for i in range(N):
    dA[i] = ((Ag[0]-A[i][0])**2+(Ag[1]-A[i][1])**2)**0.5
    dB[i] = ((Bg[0]-B[i][0])**2+(Bg[1]-B[i][1])**2)**0.5

dA.sort()
dB.sort()

print(dB[-1]/dA[-1])