N=int(input())
S=input()

a=S.count('A')
b=S.count('B')
c=S.count('C')
d=S.count('D')
e=S.count('F')
sum=(4*a+3*b+2*c+1*d+e*0)/N
print(sum)