N,M=map(int,input().split())
list1=[]
for i in range(N):
    b=input()
    list2=[]
    for j in range(M):
        list2.append([int(b[j]),0])
    list1.append(list2)
    
#print(list1)

for a in range(N-2):
    for b in range(1,M-1):
        if list1[a][b][0]>=1:
            list1[a+1][b][1]+=list1[a][b][0]
            list1[a+1][b-1][0]-=list1[a][b][0]
            list1[a+1][b+1][0]-=list1[a][b][0]
            list1[a+2][b][0]-=list1[a][b][0]
            list1[a][b][0]=0
#print(list1)

for x in range(N):
    ans=""
    for y in range(M):
        ans=ans+str(list1[x][y][1])
    print(ans)