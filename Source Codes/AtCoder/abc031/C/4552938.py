n = int(input())
a = list(map(int,input().split()))

ans = -float("inf") 
for i in range(n):
  max_aoki = -float("inf") 
  for j in range(n):
    if i != j:
      num1 = i
      num2 = j
      if j < i:
        num2 = i
        num1 = j
      aoki = sum(a[num1:num2+1][1::2])
      takahashi = sum(a[num1:num2+1][::2])
      if aoki > max_aoki:
        max_aoki = aoki
        max_takahashi = takahashi
  ans = max(ans,max_takahashi)
print(ans)