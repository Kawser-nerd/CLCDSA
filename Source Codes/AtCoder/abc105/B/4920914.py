N = int(input())
count = 0

for i in range(N):
    for j in range(N):
        if N == 4*i + 7*j:
            count += 1
            break

print('Yes' if count > 0 else 'No')