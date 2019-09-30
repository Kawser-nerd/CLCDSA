XY = list(map(int, input().split('/')))
X=XY[0]
Y=XY[1]
N1=int(2*X/Y-1)
N2=int(2*X/Y+0)
N3=int(2*X/Y+1)
M1=N1*((N1+1)*Y-2*X)//(2*Y)
M2=N2*((N2+1)*Y-2*X)//(2*Y)
M3=N3*((N3+1)*Y-2*X)//(2*Y)

def judge(N, M, X, Y):
    if N <= 0:
        return False
    if M <= 0 or M > N:
        return False
    return Y*(N*(N+1)//2-M)==N*X

if N1 > N2:
    N1, N2 = N2, N1
if N1 > N3:
    N1, N3 = N3, N1
if N2 > N3:
    N2, N3 = N3, N2

flag = False
if judge(N1, M1, X, Y):
    print(N1, M1)
    flag = True
if N1 != N2 and judge(N2, M2, X, Y):
    print(N2, M2)
    flag = True
if N2 != N3 and judge(N3, M3, X, Y):
    print(N3, M3)
    flag = True

if flag == False:
    print("Impossible")