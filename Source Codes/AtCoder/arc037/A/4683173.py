n = int(input())
m = list(map(int,input().split()))
t = 0
for c in m:t += max(0,80-c)
print(t)