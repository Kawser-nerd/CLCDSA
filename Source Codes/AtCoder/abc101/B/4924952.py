s=input()
sn=0
for i in range(len(s)):
    sn+=int(s[i])    


print("Yes" if int(s)%sn==0 else "No")