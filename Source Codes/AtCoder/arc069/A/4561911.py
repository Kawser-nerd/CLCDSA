s,c=map(int,input().split())
a=min(s,c//2)
c-=s*2
a+=max(0,c//4)
print(a)