str=input()
n=int(input())

lr=[]
for i in range(n):
    lr.append(input().split(" "))

for i in range(n):
    lr[i][0]=int(lr[i][0])
    lr[i][1]=int(lr[i][1])

num=[]
for i in range(len(str)):
    num.append(int(i))

for i in range(n):
    for j in range(1+(lr[i][1]-lr[i][0])//2):
        num[lr[i][0]-1+j],num[lr[i][1]-1-j]=num[lr[i][1]-1-j],num[lr[i][0]-1+j]

for i in num:
    print(str[i],end="")
print("")