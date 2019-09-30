N = list(input())

if len(set(N[:-1])) == 1 or len(set(N[1:]))==1:
    print('Yes')
else:
    print('No')