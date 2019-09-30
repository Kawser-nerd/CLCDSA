# -*- coding: utf-8 -*-
x,y = map(int, input().split())

if abs(x-y)<=1:
    print("Brown")
else:
    print("Alice")