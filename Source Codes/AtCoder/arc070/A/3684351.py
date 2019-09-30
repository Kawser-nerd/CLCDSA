x = int(input())
import math
huga = int((-1 + math.sqrt(1+8*x))/2)

if huga*(huga+1) == 2*x:
    print(huga)
else:
    print(huga+1)