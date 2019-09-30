a = int(input())
x=list(map(int,input().split()))
import itertools
x.sort()
c=list(itertools.accumulate(x))
s = 0
c=c[::-1]
x = x[::-1]
#print(c)
#print(x)
for i,(t,l) in enumerate(zip(c[1:],x[:-1])):
    #print(t,l)
    if t*2 >= l  :s+=1
    else:break
print(s+1)