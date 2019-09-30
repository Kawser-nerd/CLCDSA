n=int(input())
s=input()
a=['SS','SW','WS','WW']
for j in range(4):
    for i in range(1,n):
        if s[i]=='o':
            if a[j][i]=='S':
                if a[j][i-1]=='S':
                    a[j]+='S'
                else:
                    a[j]+='W'
            else:
                if a[j][i-1]=='S':
                    a[j]+='W'
                else:
                    a[j]+='S'
        else:
            if a[j][i]=='S':
                if a[j][i-1]=='S':
                    a[j]+='W'
                else:
                    a[j]+='S'
            else:
                if a[j][i-1]=='S':
                    a[j]+='S'
                else:
                    a[j]+='W'
ans='-1'
for j in range(4):
    if a[j][0]==a[j][-1]:
        if s[0]=='o':
            if a[j][0]=='S' and a[j][-2]==a[j][1]:
                ans=a[j][:-1]
                break
            if a[j][0]=='W' and a[j][-2]!=a[j][1]:
                ans=a[j][:-1]
                break
        if s[0]=='x':
            if  a[j][0]=='S' and a[j][-2]!=a[j][1]:
                ans=a[j][:-1]
                break
            if  a[j][0]=='W' and a[j][-2]==a[j][1]:
                ans=a[j][:-1]
                break
print(ans)