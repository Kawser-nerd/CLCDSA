import bisect
N = int(input())
boxes = [int(input())]

for i in range(N-1):
  j = int(input())
  if max(boxes) < j:
    boxes.append(j)
  else:
    index = bisect.bisect_left(boxes, j)
    boxes[index] = j
print(len(boxes))