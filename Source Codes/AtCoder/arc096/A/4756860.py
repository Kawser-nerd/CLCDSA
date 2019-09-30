#! /usr/bin/python 
# -*- coding: utf-8 -*- 
#===============================================================================
# Date created  : 2019-03-30T11:10:44+09:00
# Date modified : 2019-03-30T11:10:44+09:00
# Author        : awk
# Description   : unanswered
#===============================================================================


A , B , C , X , Y = map(int,input().split())
cost = []

for i in range(10**5 + 1):
    # 2i ??AB?????
    x = i
    y = i
    a = max(X - i, 0)
    b = max(Y - i, 0)
    cost.append(A * a + B * b + C * 2 * i)
print(min(cost))