k = int(input())
a = list(map(int,input().split()))
a = a[::-1]

c = 2 #min
d = 2 #max
res = 1 #??

for i in range(k):
    if d < a[i]:
        res = -1
        break
    if i != k-1:
        if c % a[i] != 0 or d % a[i] != 0:
            res = -1
            break
        else:
            d = d + a[i] -1
            p = c%a[i+1]
            q = d%a[i+1]
            if p == 0:
                c2 = c
            else:
                c2 = c + a[i+1]-p
            d2 = d-q
            
            if c2 <= d2:
                c = c2
                d = d2
            else:
                res = -1
                break
    else:
        d = d + a[i] -1
            
        
    
    
if res == -1:
    print(-1)
else:
    print(str(c) + ' ' + str(d))