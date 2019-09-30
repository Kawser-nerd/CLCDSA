m, n, N = map(int, input().split())
N = [N, 0]
cou = 0

while True:
    cou += N[0]
    re1 = N[0] + N[1]
    N = [re1//m*n, re1%m]
    if N[0] == 0:
        break
    
print(cou)