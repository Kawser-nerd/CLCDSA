N,M=map(int,input().split())
pic=[list(input()) for _ in range(N)]
temp=[list(input()) for __ in range(M)]
flag=0
for i in range(N-M+1):
    if flag==0:
        for j in range(N-M+1):
            if all(pic[x+j][i:i+M]==temp[x] for x in range(M)):
                print("Yes")
                flag=1
                break
if flag==0:print("No")