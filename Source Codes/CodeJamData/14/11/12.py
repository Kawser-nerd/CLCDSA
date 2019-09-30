def flips(a, b):
    result = ''
    for i in range(len(a)):
        result += '0' if a[i] == b[i] else '1'
    return result

def flop(a, b):
    result = ''
    for i in range(len(a)):
        result += a[i] if b[i] == '0' else '1' if a[i] == '0' else '0'
    return result


for t in range(int(input())):
    N, L = map(int, input().split())
    start = input().split()
    goal = input().split()
    minimum = 1000
    first = start[0]
    for g in goal:
        flip = flips(g, first)
        popcount = flip.count('1')
        if popcount < minimum:
            outlets = set(start)
            devices = set(map(lambda a: flop(a, flip), goal))
            if outlets == devices:
                minimum = popcount
        
    
    result = 0
    print('Case #{}: {}'.format(t+1, minimum if minimum != 1000 else 'NOT POSSIBLE'))
