n,m = map(int,input().split())
a = list(map(int,input().split()))
sums = [0]
sum = 0
ans = 0

for i in range(n):
    sum += a[i]
    sums.append(sum)



dic = {}

for i in range(n+1):
    dic.setdefault(str(sums[i]%m),0)
    dic[str(sums[i]%m)] += 1

for key in dic.keys():
    k = dic[key]
    if k>1:
        ans += k*(k-1)//2

print(ans)