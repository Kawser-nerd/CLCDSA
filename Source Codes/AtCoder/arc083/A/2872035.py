a, b, c, d, e, f = list(map(int, input().split()))
ans1, ans2 = 100*a, 0
t = 0
for i in range(31):
  for j in range(31):
    if i==j==0:
      break
    w = (a*i+b*j)*100
    if w>f:
      break
    for k in range((f-w)//c+1):
      for l in range((f-w)//d+1):
        s = c*k+d*l
        if w+s>f:
          break
        if w/100*e<s:
          break
        if t<100*s/(w+s):
          ans1 = w+s
          ans2 = s
          t = 100*s/(w+s)
print(ans1, ans2)