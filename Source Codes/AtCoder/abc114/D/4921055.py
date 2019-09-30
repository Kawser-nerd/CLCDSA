N=int(input())

e=[0]*(N+1)

for i in range(N+1):
    cur=i

    for j in range(2,i+1):
        while cur%j==0:
            e[j]+=1
            cur=cur//j

def num(m):
    tmp=0
    for i in range(N+1):
        if e[i]>=m:
            tmp+=1
    return tmp

print(num(74)+num(24)*(num(2)-1)+num(4)*(num(4)-1)*(num(2)-2)//2+num(14)*(num(4)-1))