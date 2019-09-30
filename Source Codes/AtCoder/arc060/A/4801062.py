N,A = map(int,input().split())
X = [int(x)-A for x in input().split()]

d = {0:1}  

for x in X:
    d_tmp = d.copy()
    for k in d_tmp:        
        d[k+x] = d.get(k+x,0)+d_tmp[k]
print(d[0]-1)