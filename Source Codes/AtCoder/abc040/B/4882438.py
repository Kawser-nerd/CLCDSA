N = int(input())

res = float("inf")
for i in range(500):
    for j in range(500):
        if i*j > N:
            continue
        score = abs(i-j) + (N-(i*j))
        res = min(res,score)

print(res)