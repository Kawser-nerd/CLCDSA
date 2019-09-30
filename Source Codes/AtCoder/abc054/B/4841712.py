N, M = map(int, input().split())
A = [input() for _ in range(N)]
# print(A)

B = [input() for _ in range(M)]
# print(B)

ans = "No"
for i in range(N-M+1):
    for j in range(N-M+1):
        check = True
        for k in range(M):
            for l in range(M):
                if A[i+k][j+l] != B[k][l]:
                    check = False
        if check == True:
            ans = 'Yes'
print(ans)