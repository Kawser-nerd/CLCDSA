n = int(input())
T = [int(t) for t in input().split()]
m = int(input()) # num of drinks
drinks = []
diffs = [0 for _ in range(n)] # diff buffs

for i in range(m):
    p, x = map(int, input().split())
    drinks.append([p,x])

for drink in drinks:
    diff = T[drink[0]-1] - drink[1] # ????? - ???????
    print(sum(T)-diff)