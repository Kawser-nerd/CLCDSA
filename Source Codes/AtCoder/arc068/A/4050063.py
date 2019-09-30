# -*- coding: utf-8 -*-
"""
Created on Sun Jan 20 16:07:45 2019

@author: Yamazaki Kenichi
"""

x = int(input())

ans=0

ans += 2*(x//11)
if x%11 == 0:
    ans +=0
else:
    ans += 2 if x%11 >6 else 1

print (ans)