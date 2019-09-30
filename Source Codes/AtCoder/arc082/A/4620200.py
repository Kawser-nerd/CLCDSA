input();a=[0]*100000
for i in input().split():a[int(i)]+=1
print(max(map(sum,zip(a,a[1:],a[2:]))))