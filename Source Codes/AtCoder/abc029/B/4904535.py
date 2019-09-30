import sys
a = 0
for i in sys.stdin:
  if "r" in i:
    a += 1
print(a)