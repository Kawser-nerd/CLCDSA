s=list(input())
ans=[]
for i in range(len(s)):
    if s[i]=="0":
        ans.append('0')
    elif s[i]=="1":
        ans.append('1')
    elif len(ans)!=0:
        del ans[-1]
    else:
        continue
print(''.join(ans))