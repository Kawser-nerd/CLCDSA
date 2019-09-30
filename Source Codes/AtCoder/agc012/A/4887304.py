N = int(input())
a = list(map(int,input().rstrip().split()))
a.sort(reverse=True)
total = 0
for i in range(2*N):
    if i%2 == 1:
        total += a[i]
    else:
        continue
print(total)