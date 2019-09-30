N,M=map(int,input().split())
relation_map=[[0 for i in range(N)] for j in range(N)]
for i in range(M):
    x,y=map(int,input().split())
    relation_map[x-1][y-1]=1
    relation_map[y-1][x-1]=1

member=0
for b in range(1,2**N):
    binary=bin(b)
    candidate=[int(i) for i in list(binary[2:].zfill(N))]  #bin
    
    flag=True
    cnt=0
    for i in range(N-1):
        if candidate[i]==0:
            pass
        else:
            for j in range(i+1,N):
                if candidate[j]==0:
                    pass
                else:
                    flag=True if relation_map[i][j]==1 else False
                if flag==False:
                    break
            if flag==False:
                break
    if flag==False:
        member=max(member,cnt)
    else:
        cnt=sum(candidate)
        member=max(member,cnt)
print(member)