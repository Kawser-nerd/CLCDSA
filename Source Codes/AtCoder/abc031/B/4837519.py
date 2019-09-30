l,h=map(int,input().split(' '))
n=int(input())
a=[]
for i in range(n):
    a.append(int(input()))
for i in range(n):
        if a[i]<l:
            print(int(l-a[i]))
        elif a[i]<=h:
            print(0)
        else:
            print(str(-1))