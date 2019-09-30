# -*- coding utf-8 -*-

a,b = map(int,input().split())

if a==1 and b==1:
    print("Draw")
elif a==1:
    print("Alice")
elif b==1:
    print("Bob")
elif a>b:
    print("Alice")
elif b>a:
    print("Bob")
elif a==b:
    print("Draw")