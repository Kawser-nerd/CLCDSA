a = list(map(int,input().split()))

a.sort()
aa = []
for i in range(3):
    for j in range(1+i,4):
        for k in range(1+j,5):
            if not a[i]+a[j]+a[k] in aa:
                aa.append(a[i]+a[j]+a[k])

aa.sort()
print(aa[-3])