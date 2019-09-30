N = int(input())
matrix = [ list(map(int,input()) ) for _ in range(N)]
ans = 1 
for i in range(N):
    if matrix[i][i] == 0:
        for j in range(i,N):
            if matrix[j][i] == 1 :
                matrix[i], matrix[j] = matrix[j] ,matrix[i]
                break
    if matrix[i][i] == 0:
        ans = 0
        break
    for j in range(i+1,N):
        if matrix[j][i] == 1 :
            for k in range(N):
                matrix[j][k] ^= matrix[i][k]
    

print ("Even" if ans %2 ==  0 else "Odd")