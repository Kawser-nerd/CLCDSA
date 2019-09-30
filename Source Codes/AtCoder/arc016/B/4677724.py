n=int(input())
a=[list(input()) for i in range(n)]+["."*9]
c=0
for i in range(n):
    for j in range(9):
        if a[i][j]=="x":
            c+=1
        if a[i][j]=="o" and a[i+1][j]!="o":
            c+=1
print(c)