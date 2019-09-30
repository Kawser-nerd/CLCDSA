n=int(input())
s=input()

def f(s,t):
    a=set(s)
    b=set(t)
    c=a&b
    return len(c)

x=0
for i in range(1,n-1):
    str1=s[0:i]
    str2=s[i:n]
    x=max(x,f(str1,str2))
print(x)