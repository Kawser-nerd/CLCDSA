A=int(input())
B=int(input())
C=int(input())
X=int(input())
cont = 0
total = 0
a = 500
b = 100
c = 50
for i in range(0,A+1):
    for j in range(0,B+1):
        for k in range(0,C+1):
            total = a*i + b*j + c*k
            if total == X:
                cont += 1
print(cont)