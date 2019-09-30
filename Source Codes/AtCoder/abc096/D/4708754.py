n = int(input())
num = list(range(2,2000))[::-1]
pri = []
while num:
  p = num.pop()
  pri.append(p)
  num = [i for i in num if i%p]
five = [i for i in pri if i%5==1]
ans = five[:n]
print(" ".join(map(str,ans)))