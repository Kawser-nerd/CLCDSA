N,A,B=map(int,input().split())
x=map(int,input().split())
ls=[]
a=0
for i in x:
     ls.append(i)
for i in range(len(ls)-1):
     result=ls[i+1]-ls[i]
     if result*A>B:
          a+=B
     else:
          a+=result*A
print(a)