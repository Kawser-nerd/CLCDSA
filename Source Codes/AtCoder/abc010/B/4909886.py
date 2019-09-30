n = int(input())
as_ = list(map(int, input().split()))
 
ans = 0
for i in range(n):
  while as_[i]%2 == 0 or as_[i]%3 == 2:
    ans += 1
    as_[i] -= 1
print(ans)