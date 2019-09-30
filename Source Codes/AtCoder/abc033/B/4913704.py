n = int(input())
s=[]
for i in range(n):
    s.append(list(input().split()))
m=0
name = 'atcoder'
for j in range(n):
    m+=int(s[j][1])

for k in range(n):
    if int(s[k][1])>m/2:
        name = s[k][0]

print(name)