B = int(input())
T, A = map(int, input().split())
N = map(int, input().split())
i = 9999
j = 1
for ids,k in enumerate(N):
  if abs(A - (T - k * 0.006)) < i : 
    i = abs(A - (T - k * 0.006))
    j = ids

print(j + 1)