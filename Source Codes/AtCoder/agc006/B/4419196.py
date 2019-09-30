n, x = map(int, input().split())
if x in [1, 2*n-1]:
    print("No")
else:
    print("Yes")
    mid = [x-1,x,x+1]
    if x != 2*n-2:
        mid = [x+2]+mid
    if x != 2:
        mid += [x-2]
    hoge = [i for i in range(1,2*n) if i not in mid]
    ans = hoge[:n-2] + mid + hoge[n-2:]
    print(*ans,sep="\n")