N, A, B = map(int, input().split())
for i in range(10000):
    if i % 2 == 0:
        N -= A
        if N <= 0:
            print('Ant')
            break
    else:
        N -= B
        if N <= 0:
            print('Bug')
            break