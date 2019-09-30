ans = 0
num = int(input())
for i in range(1, num+1):
  ans += i*10000/num
print(int(ans))