c=0;_,*s=open(0)
for t in s[::-1]:a,b=map(int,t.split());c+=(-a-c)%b
print(c)