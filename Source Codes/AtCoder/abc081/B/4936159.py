N = int(input())
A = list(map(int, input().split()))
cau = 0
flag = True
while flag:
    for i in range(N):
        if A[i] % 2 == 1:
            flag = False
            break        
    if flag:
        for i in range(N):
            A[i] = A[i]/2
        cau += 1
print(cau)