N = int(input())

ls = [i for i in range(1,N+1)]
import itertools
plist = list(itertools.combinations(ls,2))
ls = []
cnt=0
all_pattern = len(plist)
if N % 2== 0:
    print(all_pattern-(N//2))
    idx_x = N
else:
    print(all_pattern-(N-1)//2)
    idx_x = N-1
idx_y = 1
for p in plist:
    if p[0] == idx_y and p[1]==idx_x:
        idx_x = idx_x -1
        idx_y = idx_y +1
    else:
        print(p[0],p[1])