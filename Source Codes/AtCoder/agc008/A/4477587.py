input_nums = [int(c) for c in input().split(" ")]
x = input_nums[0]
y = input_nums[1]
ad = 0

if x > y:
  ad = 2
if (x < 0 and y > 0) or (x >= 0 and y <= 0):
  ad = 1
if x == y:
  ad = 0

x, y = abs(x), abs(y)

print(abs(x-y)+ad)