s=input()+'TE'
x,y=list(map(int,input().split()))

ini = s.find('T')
s=s[ini+1:]

is_y=1
point=[set([ini]),set([0])]

while len(s)>1:
    tmp=s.find('T')
    if tmp != 0:
        set_=set()
        for z in point[is_y]:
            set_.add(z+tmp)
            set_.add(z-tmp)
        point[is_y]=set_
    is_y+=1
    is_y%=2
    s=s[tmp+1:]

if x in point[0] and y in point[1]:
    print('Yes')
else:
    print('No')