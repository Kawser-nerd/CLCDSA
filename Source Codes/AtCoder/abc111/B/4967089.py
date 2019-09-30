#N = list(map(int, input()))
N = int(input())

list = [111,222,333,444,555,666,777,888,999, 1000000]
ans = 0
for l in list:
  if N > l:
    continue
  else:
    ans =l
    break

print(ans)