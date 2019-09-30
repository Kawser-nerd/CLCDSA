N = int(input())
a_s = list(map(int,input().split()))
a_s.sort()
a_s.reverse()
sum = 0
for i in range(N):
  sum += a_s[2*i + 1]
print(sum)