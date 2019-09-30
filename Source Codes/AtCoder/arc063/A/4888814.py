S = [i for i in input()]
ans = 0
for i in range(len(S)-1):
    if S[i]=="W" and S[i+1]=="B":
        ans+=1
    elif S[i]=="B" and S[i+1]=="W":
        ans+=1
print(ans)