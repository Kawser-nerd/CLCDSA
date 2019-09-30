a, b, c = list(map(int, input().split()))
li = [a * 10 + b + c, c * 10 + a + b, b * 10 + a + c]
print(max(li))