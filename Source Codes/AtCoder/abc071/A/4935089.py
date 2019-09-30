x, a, b = list(map(int, input().split()))
print("AB"[abs(x-a) > abs(x-b)::2])