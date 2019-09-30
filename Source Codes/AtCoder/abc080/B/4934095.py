N = int(input())
f = sum(list(map(int, str(N))))
if N % f == 0:
    print('Yes')
else:
    print('No')