s = input()

bestdif = 1000
for i in range(len(s)-2):
  if bestdif > abs(753 - int(s[i:i+3])):
    bestdif = abs(753 - int(s[i:i+3]))
print(bestdif)