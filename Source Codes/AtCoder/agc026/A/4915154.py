n = int(input())
a = list(map(int, input().split()))
cnt = 0
for i in range(n-1) :
  if(a[i] == a[i+1]) :
    cnt += 1
    a[i+1] = 0
print(cnt)