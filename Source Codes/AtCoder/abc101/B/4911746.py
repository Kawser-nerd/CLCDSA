# -*- coding: utf-8 -*-

N = int(input())
n = list(map(int, str(N)))

print('Yes' if N % sum(n) == 0 else 'No')