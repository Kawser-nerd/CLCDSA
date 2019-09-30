n = int(input())
s = list(map(int,input().split()))
s.sort()
sum = 0

for i in range(0,2*n,2):
  sum += s[i]
print(sum)