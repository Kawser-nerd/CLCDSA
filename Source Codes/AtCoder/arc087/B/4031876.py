s=input()
x,y=map(int, input().split())
sl=[len(i) for i in s.split('T')]
a,b={0:1},{0:1}
for i in sl[2::2]:
    if i==0:continue
    a2={}
    for j in a.keys():
        a2[j+i]=1
        a2[j-i]=1
    a=a2
for i in sl[1::2]:
    if i==0:continue
    b2={}
    for j in b.keys():
        b2[j+i]=1
        b2[j-i]=1
    b=b2
if x-sl[0] in a and y in b:print('Yes')
else:print('No')