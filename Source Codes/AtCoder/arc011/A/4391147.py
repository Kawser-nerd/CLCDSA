m, n, N = map(int, input().split())

res = N
tmp = N
g = 0
while True:
    e = 0
    flag = False
    for i in range(tmp):
        g += 1
        if g == m:
            res += n
            g = 0
            e += n
            flag = True
            
    if flag == False:
        break
        
    tmp = e
        
    
print(res)