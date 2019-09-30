N,M = map(int,input().split())
py_list = []
d = dict()
for i in range(M):
    p,y = map(int,input().split())
    py_list.append([p,y])
py_sorted =  sorted(py_list)
p_temp = py_sorted[0][0]
count = 1
for p,y in py_sorted:
    if p_temp != p:
        p_temp = p
        count = 1
    d[(p,y)] = count
    count += 1

for i in range(M):
    s = d[(py_list[i][0],py_list[i][-1])]
    s = str(s)
    ss = str(py_list[i][0]).zfill(6) + s.zfill(6)
    print(ss.strip())