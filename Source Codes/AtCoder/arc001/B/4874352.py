a = [0, 0, 0, 0]
N = int(input())
row = input()

for i in range(N):
  a[int(row[i]) - 1] += 1

print(max(a), min(a))