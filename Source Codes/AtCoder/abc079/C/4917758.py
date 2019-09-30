import sys
from sys import stdin
abcd = [int(c) for c in list(stdin.readline().rstrip())]
op = ['+', '-']
for i in op:
    for j in op:
        for k in op:
            result=abcd[0]
            if i == '+':
                result+=abcd[1]
            else:
                result-=abcd[1]
            if j == '+':
                result+=abcd[2]
            else:
                result-=abcd[2]
            if k == '+':
                result+=abcd[3]
            else:
                result-=abcd[3]
            if result == 7:
                print(abcd[0], end='')
                print(i, end='')
                print(abcd[1], end='')
                print(j, end='')
                print(abcd[2], end='')
                print(k, end='')
                print(abcd[3], end='')
                print('=7')
                sys.exit()