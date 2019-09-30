N = int(input())
a =list(map(int, input().split()))
ans = 0
a_all = 1
for i in range(N):
  a_all = a_all*a[i]

for i in range(N):
  ans += (a_all -1) % a[i]
print(ans)