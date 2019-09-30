n = int(input())
as_ = list(map(int, input().split()))

if sum(as_)%n != 0:
  print('-1')
else:
  m = int(sum(as_)/n)
  sum_ = 0
  count_ = 0
  ans = 0
  for i in range(n):
    sum_ += as_[i]
    count_ += 1
    if sum_ == count_*m:
      ans += count_-1
      sum_ = 0
      count_= 0
  print(ans)