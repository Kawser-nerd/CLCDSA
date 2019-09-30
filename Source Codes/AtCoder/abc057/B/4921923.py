N,M=map(int,input().split())
st=[list(map(int,input().split())) for i in range(N)]
ch=[list(map(int,input().split())) for i in range(M)]
for s in st:
    Min=1000000000
    Mindex=-1
    for i in range(M):
        if abs(ch[i][0]-s[0])+abs(ch[i][1]-s[1])<Min:
            Min=abs(ch[i][0]-s[0])+abs(ch[i][1]-s[1])
            Mindex=i+1
    print(Mindex)