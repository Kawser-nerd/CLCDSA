N = int(input())
S = input().split()

if len(set(S)) == 3:
    print('Three')
else:
    print('Four')