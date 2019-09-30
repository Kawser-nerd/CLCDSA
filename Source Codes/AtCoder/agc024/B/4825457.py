n=int(input())
s=[0]*(n+1)
for i in range(n):
    a=int(input())
    s[a]=s[a-1]+1
print(n-max(s))