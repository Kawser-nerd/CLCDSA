n = int(input())
a = [int(i) for i in input().split()]

count = 1
pre = a[0]
res = 0
for x in a[1:]:
    if pre < x:
        count+=1
    else:
        res += sum([i for i in range(count+1)])
        count = 1
    pre = x

res += sum([i for i in range(count+1)])
print(res)