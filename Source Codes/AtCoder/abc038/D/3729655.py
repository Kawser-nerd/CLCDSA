import bisect

N=int(input())
WH=[list(map(int,input().split())) for i in range(N)]
WH.sort(key=lambda x:x[1],reverse=True)
WH.sort(key=lambda x:x[0])

ANS=[[0,0]]


for w,h in WH:
    x=bisect.bisect_left(ANS,[h,0])
    if x<len(ANS) and ANS[x][1]==ANS[x-1][1]+1:
        ANS[x][0]=h
    else:
        bisect.insort(ANS,[h,ANS[x-1][1]+1])

    #print(ANS)
    
print(max(ANS,key=lambda x:x[1])[1])