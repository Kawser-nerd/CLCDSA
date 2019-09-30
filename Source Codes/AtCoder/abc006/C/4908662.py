N,M = map(int,input().split())
grand = M%2
child = (M-2*N)//2
man = N - grand - child
if man < 0 or child < 0:
    print('-1 -1 -1')
else:
    print(man,grand,child)