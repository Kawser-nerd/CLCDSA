a500 = int(input())
b100 = int(input())
c50 = int(input())
X = int(input())
ans = 0
goukei = 0
is_over = False
for i in range(a500+1):
  for j in range(b100+1):
    for k in range(c50+1):
      goukei = i * 500 + j * 100 + k * 50
      if goukei == X:
        ans += 1
        break
print(ans)