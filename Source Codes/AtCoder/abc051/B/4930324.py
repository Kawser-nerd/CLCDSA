k,s=map(int,input().split())
cnt=0
for x in range(0,k+1):
    for y in range(0,k+1):
        if s-x-y>=0 and s-x-y<=k:
            cnt+=1
print(cnt)