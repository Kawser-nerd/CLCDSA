n = int(input())
a = [111,222,333,444,555,666,777,888,999]
result = 0
for i in a:
  if i >= n:
    result = i
    break
print(result)