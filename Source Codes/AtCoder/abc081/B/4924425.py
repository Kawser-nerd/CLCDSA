n = int(input())
alist = [int(_) for _ in input().split()]

result = []
for a in alist:
  each_result = 0
  while a%2 == 0:
    a = a/2
    each_result = each_result + 1
  result.append(each_result)

print(min(result))