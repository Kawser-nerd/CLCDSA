import bisect
from collections import defaultdict
n = int(input())
a = list(map(int, input().split()))
color_list = [1, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200]
color_dict = defaultdict(int)
red_count = 0
for i in a:
  idx = bisect.bisect_right(color_list, i)
  if 1 <= idx <= 8:
    color_dict[idx] += 1
  elif idx == 9:
    red_count += 1
if len(color_dict) >= 1:
  print(len(color_dict), len(color_dict)+red_count)
else:
  print(1, red_count)