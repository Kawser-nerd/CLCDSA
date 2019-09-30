s=input()
a=list(map(int,input().split()))
for i in range(4):
    s=s[:i+a[i]]+"\""+s[i+a[i]:]
print(s)