N,K = map(int,input().split())
A = [int(a) for a in input().split()]

dic = {}                
for a in A:
    dic[a] = dic.get(a,0) + 1
    
C = []
for k in dic:
    C.append([k,dic[k]])
    
C.sort(key = lambda x: x[1])

if len(C)<=K:
    print(0)
else:
    print(sum([x[1] for x in C[:len(C)-K]]))