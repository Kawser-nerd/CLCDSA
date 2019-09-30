a,b,c,x = [int(input()) for _ in range(4)]
# 500 100 50

result = 0
for aa in range(a+1):
  for bb in range(b+1):
    for cc in range(c+1):
      if x == aa*500 + bb * 100 + cc * 50:
        result = result + 1

print(result)