n,l = map(int,input().split())
s=[]
for i in range(n):
    s.append(input())
ans=sorted(s)
print(''.join(ans))