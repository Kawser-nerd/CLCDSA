# -*- coding: utf-8 -*-


N = int(input())

As = list(map(int, input().split()))

if min(As) >= 0:
    print(len(As)-1)
    for i in range(len(As)-1):
        print(i+1, i+2)
elif max(As) <= 0:
    print(len(As)-1)
    for i in range(len(As)-1,0,-1):
        print(i+1, i)
elif abs(max(As)) >= abs(min(As)):
    max_index = As.index(max(As))
    print(len(As)*2-1)
    for i in range(len(As)):
        print(max_index+1, i+1)
    for i in range(len(As)-1):
        print(i+1, i+2)
else:
    min_index = As.index(min(As))
    print(len(As)*2-1)
    for i in range(len(As)):
        print(min_index+1, i+1)
    for i in range(len(As)-1,0,-1):
        print(i+1, i)