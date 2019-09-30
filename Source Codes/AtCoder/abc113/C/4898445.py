N,M = map(int,input().split())
lis  = [list(map(int,input().split())) for _ in range(M)]
ans_lis = [0] * M
lis_sort = sorted(lis,key =lambda x:(x[0],x[1]))
flag = lis_sort[0][0]
i = 1
for x in lis_sort:
    if x[0] != flag:
        flag = x[0]
        i=1
    x[1] = '0'*(6-len(str(i)))+str(i)
    i+=1
for x in lis:
    print('0'*(6-len(str(x[0]))),str(x[0]),x[1],sep='')