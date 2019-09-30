a,b,c=map(int,input().split(' '))
A=a+b
B=a-b
if A==c and B==c:
    print('?')
elif A==c and B!=c:
    print('+')
elif A!=c and B==c:
    print('-')
else:
    print('!')