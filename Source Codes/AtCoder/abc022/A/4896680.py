N, S, T = map(int, input().split())

W = int(input())
count = 1 if S <= W <= T else 0
for n in range(N - 1):
    W += int(input())
    if S <= W <= T:
        count += 1
        
print(count)