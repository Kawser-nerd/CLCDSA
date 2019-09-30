c=0
for t in open(0).readlines()[:0:-1]:a,b=map(int,t.split());c+=(-a-c)%b
print(c)