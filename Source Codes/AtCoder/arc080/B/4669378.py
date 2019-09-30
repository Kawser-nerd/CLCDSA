h,w = map(int,input().split())
lis = []
ans = []
nu = 0
nn = int(input())
li = list(map(int,input().split()))
for i in range(nn):
    for j in range(li[i]):
        if nu % 2 == 0:
            lis.append(str(i+1))
        else:
            lis.insert(0,str(i+1))
        if len(lis) == w:
            ans.append(str(" ".join(lis)))
            lis = []
            nu += 1
for i in range(h):print(ans[i])