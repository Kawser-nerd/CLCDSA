a = list(input())
ans= []

for i in range(len(a)-2):
    X = a[i]
    Y = a[i + 1]
    Z = a[i + 2]
    aa = X + Y + Z
    ee = abs(753 - int(aa))
    ans.append(ee)

    
print(min(ans))