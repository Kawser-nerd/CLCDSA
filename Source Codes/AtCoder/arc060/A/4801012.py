N,A = map(int,input().split())
X = [int(x)-A for x in input().split()]

z = 0 
dic = {}

for x in X:
    if x==0:
        z += 1
    else:
        dic[x] = dic.get(x,0) + 1
            
line = {}
line[0] = 1

for k in dic:    
    line_k = {}
    for i in range(dic[k]+1):
        line_k[k*i] = 1      
        for j in range(dic[k],dic[k]-i,-1):
            line_k[k*i] *= j
        for j in range(1,1+i):
            line_k[k*i] //= j
    line_tmp = {}
    for k_lk in line_k:
        for k_l in line:
            line_tmp[k_lk+k_l] = line_tmp.get(k_lk+k_l,0) + line_k[k_lk] * line[k_l]
    line = line_tmp.copy()
    
print(line[0] * (2**z) -1)