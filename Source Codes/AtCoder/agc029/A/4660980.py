s=input()
plus=0
ans=0
for i in range(len(s)):
    if s[-1-i]=="W":
        plus+=1
    else:
        ans+=plus
print(ans)