from itertools import product, combinations


N = int(input())
c = input()
    
pairs = list(map(lambda x: x[0]+x[1], product(['A','B','X','Y'], repeat=2)))

cmd_min = len(c)
for l, r in combinations(pairs, 2):
    cmd_cnt = len(c.replace(l,'L').replace(r,'R'))
    if cmd_min > cmd_cnt:
        cmd_min = cmd_cnt
    
print(cmd_min)