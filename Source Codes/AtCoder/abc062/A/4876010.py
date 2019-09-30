x, y = map(int, input().split())

d = {
 1: 0,
 3: 0,
 5: 0,
 7: 0,
 8: 0,
 10: 0,
 12: 0,
 4: 1,
 6: 1,
 9: 1,
 11: 1,
 2: 2,
}

if d[x] == d[y]:
    print('Yes')
else:
    print('No')