N = int(input())
A = list(map(int, input().split()))

ans = 0
flag = "go"
while flag == "go":
    for i in range(N):
        if A[i] % 2 != 0:
            flag = "stop"
            break
        
    if flag == "go":
        for i in range(N):
            A[i] = A[i] / 2
        ans = ans + 1
        
print(ans)