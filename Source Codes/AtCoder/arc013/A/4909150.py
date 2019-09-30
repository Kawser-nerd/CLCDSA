from itertools import*;f,g,h,*a,=map(int,open(0).read().split());l=[]
for s,t,r in permutations(a):l+=[(f//s)*(g//t)*(h//r)]
print(max(l))