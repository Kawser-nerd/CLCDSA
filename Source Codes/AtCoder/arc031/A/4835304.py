s=input()
x=len(s)
if x%2==1:
    a=s[:x//2]
    b=s[x//2+1:][::-1]
    if a==b:
        print("YES")
    else:
        print("NO")
else:
    a=s[:x//2]
    b=s[x//2:][::-1]
    if a==b:
        print("YES")
    else:
        print("NO")