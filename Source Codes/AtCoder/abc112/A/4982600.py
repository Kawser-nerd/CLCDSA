#!/usr/bin/env python
N = int(input())
if N == 1:
    print('Hello World')
else:
    M = [int(input()) for i in range(2)]
    print(sum(M))