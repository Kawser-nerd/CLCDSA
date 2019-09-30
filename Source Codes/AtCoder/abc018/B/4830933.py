s=list(input())
n=int(input())
for i in range(n):
    a,b=map(int,input().split(' '))
    s[a-1:b]=s[a-1:b][::-1]
print(''.join(s))