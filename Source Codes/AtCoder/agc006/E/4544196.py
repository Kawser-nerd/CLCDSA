n = int(input())

a = []
for i in range(3):
    aa = list(map(int,input().split()))
    a.append(aa)

for i in range(n):
    x,y,z = a[0][i],a[1][i],a[2][i]
    x,z = x-y,z-y
    if i % 2 == 0:
        if y % 6 != 2:
            print("No")
            exit()
    else:
         if y % 6 != 5:
            print("No")
            exit()       
    y = 0
    if (x,y,z) != (-1,0,1) and (x,y,z) != (1,0,-1):
        print("No")
        exit()
        


e,o = 0,0
for i in range(n):
    if i % 2 == 0:
        if a[0][i] > a[2][i]: e += 1
    else:
        if a[0][i] > a[2][i]: o += 1

e %= 2
o %= 2

el = []
ol = []
bite = [0]
bito = [0]

for i in range(n):
    if(i % 2 == 0):
        el.append(a[1][i] // 6 + 1)
        bite.append(0)
    else:
        ol.append(a[1][i] // 6 + 1)
        bito.append(0)

def sum(i,bit):
    s = 0
    while(i > 0):
        s += bit[i]
        i = i&(i-1)
    return s
 
def add(i,x,bit):
    while(i < len(bit)):
        bit[i] += x
        i += i & (-i)

signe = 0
signo = 0

for i in range(len(el)):
    signe += (i - sum(el[i],bite))
    add(el[i],1,bite)    

for i in range(len(ol)):
    signo += (i - sum(ol[i],bito))
    add(ol[i],1,bito) 



if (signe % 2 == o) and (signo % 2 == e) :print("Yes")
else :print("No")