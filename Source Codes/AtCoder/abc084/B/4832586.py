import sys
a, b = list(map(int,input().split()))
x = input()
if not (x[0:a].isdigit()) & (len(x[0:a]) == a):
    print('No')
    sys.exit()
if x[a] != '-':
    print('No')
    sys.exit()
if not (x[a+1:a+1+b].isdigit()) & (len(x[a+1:a+1+b]) == b):
    print('No')
    sys.exit()
print('Yes')