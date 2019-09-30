A,B,C,X=[int(input()) for i in range(4)]
cnt = 0
for a in range(0, A + 1):
  for b in range(0, B + 1):
    for c in range(0, C + 1):
      if a *500 + b * 100 + c * 50 == X:
        cnt += 1
print(cnt)