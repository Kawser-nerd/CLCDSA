#!/usr/bin/env python3
# -*- coding: utf-8 -*-
n,k = map(int, input().split())
r=0
t=-100
c=0
for i in range(0,n):
  a=int(input())
  if t < a:
    c = c + 1
  else:
    c = 1
  t=a
  if c >= k:
    r = r + 1
print(r)