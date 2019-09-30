s = input()
n = len(s)
a = ""
if n%2==0:
    for i in range(0,n,2):
        a += s[i]
else:
    for i in range(0,n+1,2):
        a += s[i]
print(a)