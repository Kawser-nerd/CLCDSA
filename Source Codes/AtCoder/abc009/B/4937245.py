n = int(input())
as_ = [0]*n
for i in range(n):
  as_[i] = int(input())
as_ = list(set(as_))
as_.sort()
print(as_[-2])