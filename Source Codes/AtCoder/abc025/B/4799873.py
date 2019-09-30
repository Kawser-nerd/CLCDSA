n,a,b = map(int,input().split())

m = list(list(map(str,input().split())) for i in range(n))

p = 0

for i in range(n):
    if m[i][0] == 'West':
        if int(m[i][1]) < a:
            p+= a
        elif int(m[i][1]) > b:
            p+= b
        else:
            p += int(m[i][1])
        
    if m[i][0] == 'East':
        if int(m[i][1]) < a:
            p-= a
        elif int(m[i][1]) > b:
            p-= b
        else:
            p-= int(m[i][1])
        

if p > 0:
    print('West',p)

elif p < 0:
    print('East',-p)
    
else:
    print(0)