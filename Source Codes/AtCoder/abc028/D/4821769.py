n, k = map(int, input().split())

ans = 1 + 3 * (n-1) + 6 * (k-1) * (n-k)

ans /= n
ans /= n
print(ans / n)