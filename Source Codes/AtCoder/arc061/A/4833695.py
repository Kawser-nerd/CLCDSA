S = input()
ans = 0
for i in range(1<<(len(S)-1)):
    li = []
    last = 0
    for j in range(len(S)-1):
        if((i>>j & 1)==1):
            li+=[int(S[last:j+1])]
            last = j+1
    if(last!=len(S)):
        li+=[int(S[last:])]
    ans += sum(li)
print(ans)