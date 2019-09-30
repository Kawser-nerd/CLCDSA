import math
n = int(input())
ns = list(str(n))
if(math.log10(n) == float(len(ns)-1)) : print(10)
else : print(sum([int(ns[i]) for i in range(len(ns))]))