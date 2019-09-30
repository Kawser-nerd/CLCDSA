x=int(input())
print((x//11)*2+(0 if x%11==0else(1 if x%11<7 else 2)))