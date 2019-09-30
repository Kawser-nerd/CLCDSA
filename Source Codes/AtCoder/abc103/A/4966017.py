a,b,c=map(int,input().split())
s=abs(a-b)+abs(b-c)+abs(c-a)
m=max(abs(a-b),abs(b-c),abs(c-a))
print(s-m)