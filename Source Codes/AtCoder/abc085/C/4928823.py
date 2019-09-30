#085 C

N,Y =map(int,input().split())
for i in range(N+1):
    for j in range(N-i+1):
        k=N-(i+j)
        if i * 10000 + j * 5000 + k *1000 ==Y and (i+j+k)==N:
            print(i,j,k)
            exit()
print(-1,-1,-1)