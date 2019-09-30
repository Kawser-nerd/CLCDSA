s=input()
s+=" "
t=""
cnt=1
for i in range(1,len(s)):
    if(s[i]==s[i-1]):
        cnt+=1
    else:
        t+=s[i-1]+str(cnt)
        cnt=1
print(t)