n,a,b = map(int,input().split())
v = list(map(int,input().split()))

v = sorted(v,reverse=True)
max_ave = sum(v[0:a])/a
index_max_ave = -1
for i in range(a,b+1)[::-1]:
  max_ave = max(sum(v[0:i])/(i),max_ave)
  if max_ave == sum(v[0:i])/(i):
    index_max_ave = i

print(max_ave)

def combination(n,r):
    r = min(r,n-r)
    result = 1
    for i in range(n-r+1,n+1):
        result *= i
    for i in range(1,r+1):
        result //= i
    return result


num = v[index_max_ave-1]
for i in range(index_max_ave):
  if num != v[i]:
    print(combination(v[0:index_max_ave].count(num)+v[index_max_ave:n].count(num),v[0:index_max_ave].count(num)))
    exit()

cnt = v.count(num)
ans = 0
for i in range(a,min(b+1,cnt+1)):
  ans += combination(cnt,i)
print(ans)