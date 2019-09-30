def countBA(perm):
    b = 0
    for i in range(len(perm)):
        if perm.index(i) < i: b += 1
    return b
       
def determine(perm):
    return 'BAD' if countBA(perm) > 515 else 'GOOD'

for t in range(int(input())):
    N = int(input())
    perm = list(map(int, input().split()))
    print('Case #{}: {}'.format(t+1, determine(perm)))
