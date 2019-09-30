cin, m, a, b = map(int, input().split())
for i in range(1,m+1):
  if cin <= a:
    cin += b
  cin -= int(input())
  if cin < 0:
    print(i)
    break
else:
  print("complete")