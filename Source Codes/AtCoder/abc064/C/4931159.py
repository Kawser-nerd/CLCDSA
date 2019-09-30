from collections import OrderedDict
import numpy as np

N = int(input())
a = np.array([int(i) for i in input().split()])

scores = OrderedDict()
scores[1] = 0
scores[400] = 0
scores[800] = 0
scores[1200] = 0
scores[1600] = 0
scores[2000] = 0
scores[2400] = 0
scores[2800] = 0
scores[3200] = 0

for record in a:
  for s in list(scores.keys())[::-1]:
    if record>=s:
      scores[s] += 1
      break
      
colors = np.sum([
  int(v>0) for k, v in scores.items() if k<3200])

if scores[3200]>0 and colors==0:
  min_colors = 1
else: 
  min_colors = colors
max_colors = colors + scores[3200]

print(min_colors, max_colors)