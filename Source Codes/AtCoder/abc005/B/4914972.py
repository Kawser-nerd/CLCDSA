N = int(input())
new = 100
for i in range(N):
    new = min(int(input()),new)
print(new)