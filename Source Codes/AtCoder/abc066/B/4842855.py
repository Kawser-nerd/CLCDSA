#66
s = input()
if len(s)%2==1:
    s = s[:len(s)-1]
else:
    s = s[:len(s)-2]
x = int(len(s)/2)

if s[:x]==s[x:]:
    print(2*x)
else:
    while s[:x]!=s[x:]:
        s = s[:len(s)-2]
        x -=1
    print(2*x)