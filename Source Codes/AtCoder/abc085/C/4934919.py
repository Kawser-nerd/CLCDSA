n, y = map(int, input().split())
ans_i = -1
ans_j = -1
ans_k = -1
for i in range(n+1):
    for j in range(n-i+1):
        k = n - i - j
        if 10000 * i + 5000 * j + 1000 * k == y:
            ans_i = i
            ans_j = j
            ans_k = k

print(str(ans_i) + " " + str(ans_j) + " " + str(ans_k))