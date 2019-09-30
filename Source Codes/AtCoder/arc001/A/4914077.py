n=int(input())
C=int(input())
c=[]
for i in range(n):
    c.append(C%10)
    C=C//10
num=[]
for i in range(1,5):
    num.append(c.count(i))
print(max(num),min(num))