# -*- coding: utf-8 -*-
#! python3

initial = 735369

y = int(input())
m = int(input())
d = int(input())
    
if m == 1:
    m = 13
    y -= 1
elif m == 2:
    m = 14
    y -= 1
    
days = 365*y + y//4 - y//100 + y//400 + 306*(m+1)//10 + d - 429

print(initial - days)