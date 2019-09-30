s=input()
x=len(s)
if x%2==1:
    a=s[:x//2]
    b=s[x//2+1:][::-1]
else:
    a=s[:x//2]
    b=s[x//2:][::-1]
for s,t in zip(a,b):
    if s=="*" or t=="*":
        continue
    elif s==t:
        continue
    else:
        print("NO")
        exit()
print("YES")