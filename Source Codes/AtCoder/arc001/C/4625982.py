#!/usr/bin/env python3

import re
a = input("")
a = re.split(" ",a)

n = abs(int(a[1]) - int(a[0]))

x = [1,2,3,2,1,2,3,3,2,1]

b = n//10
c = n%10

if(n != 0):
    if(c != 0):
        print(x[c-1]+b)
    else:
        print(b)
elif(n == 0):
    print(0)