N, A, B = map(int, input().split())

while True:
    N -= A
    if N <= 0:
        res = 'Ant'
        break
    N -= B
    if N <= 0:
        res = 'Bug'
        break
        
print(res)