from collections import Counter

N = int(input())
As = list(map(int, input().split()))

maxA = max(As)
minA = (maxA+1) // 2
cnt = Counter(As)

for A, num in cnt.items():
    if A < minA:
        print('Impossible')
        break
    elif A == minA:
        if (maxA % 2 and num != 2) or (maxA % 2 == 0 and num != 1):
            print('Impossible')
            break
    elif num < 2:
        print('Impossible')
        break
else:
    for A in range(minA+1, maxA+1):
        if A not in cnt:
            print('Impossible')
            break
    else:
        print('Possible')