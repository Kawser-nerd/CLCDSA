S=input()
tmp_l=0
ans=0
for i in range(len(S)):
    if S[i] in ['A','C','G','T']:
        tmp_l+=1
        if tmp_l>ans:
            ans=tmp_l
    else:
        tmp_l=0
print(ans)