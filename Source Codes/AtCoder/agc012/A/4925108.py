N = int(input())
list = [int(i) for i in input().split()]
list.sort()
result = 0
for i in list[::-1][1::2][:N]:
  result += i
print(result)