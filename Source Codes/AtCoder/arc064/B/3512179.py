# -*- coding: utf-8 -*-
s = input()
n = len(s)

if n%2==0 and s[0]!=s[n-1]:
    print("Second")
elif n%2==1 and s[0]==s[n-1]:
    print("Second")
else:
    print("First")