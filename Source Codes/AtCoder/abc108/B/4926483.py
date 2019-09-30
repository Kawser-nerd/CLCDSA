a,b,c,d=map(int,input().split())

x3=b-d+c
y3=c-a+d

x4=b-d+a
y4=c-a+b

print(str(x3) + " " + str(y3) +" "+ str(x4) +" "+ str(y4))