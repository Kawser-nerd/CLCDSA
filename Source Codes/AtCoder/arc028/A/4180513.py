N, A, B = map(int, input().split())

flag = True
while N > 0:
    if flag:
        N -= A
    else:
        N -= B
    flag = not flag

print('Ant' if not flag else 'Bug')