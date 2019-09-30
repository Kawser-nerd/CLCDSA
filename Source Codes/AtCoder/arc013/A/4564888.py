import itertools
n=list(map(int,input().split()))
d=list(itertools.permutations(list(map(int,input().split()))))
e=0
for i in range(6):
    h=1
    for j in range(3):
        h*=n[j]//d[i][j]
    else:
        e=max(h,e)
print(e)