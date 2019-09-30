N, A, B = input().split()
A = int(A)
B = int(B)
k_sum = 0
ans = 0
for j in range(1, int(N)+1):
  j = str(j)
  k_sum = 0
  for i in range(len(j)):
  	k_sum += int(j[i])
  if k_sum >= A and k_sum <= B:
    ans += int(j)
print(ans)