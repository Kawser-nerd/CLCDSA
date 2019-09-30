input()
S = list(map(int,input().split()))
i = 0
ans = 0
while True:
    if i >= len(S):
        #print('????')
        break
    for j in range(i+1,len(S)+1):
        #print(S[i:j])
        a = max(S[i:j])
        if j >= len(S):
            #print(1,S[i:j],i,j,ans)
            ans += max(S[i:j])
            i += j
            break
        elif a <= S[j]:
            #print(2,i,j,ans)
            continue
        else:
            #print(3,S[i:j],i,j,ans)
            ans += max(S[i:j])
            ans -= S[j]
            i = j
            break
print(ans)