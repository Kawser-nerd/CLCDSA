from numpy import*
n=int(input())
s=input()
x=[0]+[1 if i=="W" else 0 for i in s]
del x[-1]
y=[1 if i=="E" else 0 for i in s]
print(min(array(cumsum(x))+s.count("E")-array(cumsum(y))))