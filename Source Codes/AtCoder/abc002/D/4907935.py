import itertools

n,m = map(int,input().split())
relations = [tuple(map(int,input().split())) for _ in range(m)]

for i in range(n,0,-1):
    for j in itertools.combinations(range(1,n+1),i):
        if all((x,y) in relations for x,y in itertools.combinations(j,2)):
            print(i)
            break
    else:
        continue
    break