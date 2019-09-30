a, b = input().split()
squares = [x * x for x in range(318)]
print('Yes' if int(a + b) in squares else 'No')