x=int(input())
p=(x//11)*2
q=0 if x%11==0 else 1 if 1<=x%11<=6 else 2
print(p+q)