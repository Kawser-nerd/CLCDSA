s=input()
x=abs(s.count('R')-s.count('L'))+abs(s.count('U')-s.count('D'))
c=s.count('?')
if int(input())==1:
    print(x+c)
elif c<=x:
    print(x-c)
else:
    print((x+c)%2)