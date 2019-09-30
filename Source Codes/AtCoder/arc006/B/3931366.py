# -*- coding: utf-8 -*-

N, L = map(int, input().split())

kuji = []

for _ in range(L):
    kuji.append(input())

atari = input()
a_idx = atari.index('o')
    
kuji = kuji[::-1]

for line in kuji:
    try:
        if line[a_idx - 1] == '-':
            a_idx -= 2
        elif line[a_idx + 1] == '-':
            a_idx += 2
    except IndexError:
        continue
        
if a_idx == 0:
    print(1)
elif a_idx == 2:
    print(2)
else:
    print(a_idx//2 + 1)