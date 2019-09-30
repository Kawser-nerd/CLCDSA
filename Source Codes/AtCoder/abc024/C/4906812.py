N , D , K = map(int, input().split())
lr = [list(map(int,input().split())) for _ in range(D)]
st = [list(map(int,input().split())) for _ in range(K)]
# time ??????????????
time = [0] * K
def func(x1,y1,x2,y2 ):
    if x2 < x1 and x1 <= y2:
        x3 = x2
    else:
        x3 = x1
    if y1 < y2 and y1 >= x2:
        y3 = y2
    else:
        y3 = y1
    return x3 , y3
# d?????????????????
for i in range(K):
    d = [st[i][0] ,st[i][0]]
    j = 0
    while not( d[0] <= st[i][1] <= d[1]):
        #print("before:i:j:d:lr[j]",i,j,d,lr[j])
        d[0], d[1] = func(d[0],d[1],lr[j][0],lr[j][1])
        j += 1
        #print("after:i:j:d:lr[j]",i,j,d,lr[j])
    time[i] = j
for t in time:
    print(t)