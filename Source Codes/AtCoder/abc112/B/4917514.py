n, t = map(int,input().split())

cost = []
for i in range(n):
    x , y = map(int,input().split())
    if y > t:
        pass
    else:
        cost.append(x)

        
print('TLE' if len(cost) == 0 else min(cost))