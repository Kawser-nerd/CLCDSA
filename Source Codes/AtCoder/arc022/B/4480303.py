N = int(input())
L = list(map(int,input().split()))
TF = [False]*(10**5+1)
startindex = 0
endindex = 0
ans = 0
cnt = 0
while endindex < N:
    if TF[L[endindex]] != True:
        TF[L[endindex]] = True
        cnt += 1
        endindex += 1
        ans = max(ans,cnt)
    else:
        TF[L[startindex]] = False
        cnt -= 1
        startindex += 1
print(ans)