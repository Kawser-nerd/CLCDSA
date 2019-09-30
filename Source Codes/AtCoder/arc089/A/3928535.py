n=int(input())
s=[list(map(int,input().split()))for i in range(n)]
s.insert(0,[0,0,0])
p=0
for i in range(n):
    c=s[i+1][0]-s[i][0]
    d=abs(s[i+1][1]-s[i][1])+abs(s[i+1][2]-s[i][2])
    if c<d or (c-d)%2==1:
        p=1
        break
print("No" if p==1 else "Yes")