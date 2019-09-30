s=input().split("+")
ans=0
for i in s:
    if "0" not in i:
        ans+=1
print(ans)