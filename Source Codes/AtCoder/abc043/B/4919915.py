# -*- coding:utf-8 -*-

s = list(input())
str = ""

for x in s:
    if x != "B":
        str += x
    else:
        str = str[:-1]

print(str)