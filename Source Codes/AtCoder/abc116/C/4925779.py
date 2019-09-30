a= int(input())
b = input().split()
b= [int(s) for s in b]
check=[]
length=[]
head = 0
foot = 0
many=0
for i in range(0,a):
    length.append(0)
    check.append(0)
for i in range(0,a):
    if b[i]==length[i]:
        check[i]=1
    else:
        dum=0
for i in reversed(range(0,a)):
    if check[i]==0:
        head = i
    else:
        dum=0
for i in range(head,a):
    if check[i]==1:
        foot = i
        break
    else:
        foot = a
        dum = 0
while sum(check)!=a:
    for i in range(head,foot):
        length[i]+=1
    for i in range(0,a):
        if b[i]==length[i]:
            check[i]=1
        else:
            dum=0
    for i in reversed(range(0,a)):
        if check[i]==0:
            head = i
        else:
            dum=0
    for i in range(head,a):
            if check[i]==1:
                foot = i
                break
            else:
                foot = a
    many+=1
print(many)