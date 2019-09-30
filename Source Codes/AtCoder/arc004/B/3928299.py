N = int(input())
inputs = [int(input()) for _ in range(N)]

maximum = sum(inputs)
max_length = max(inputs)
diff = maximum - max_length
minimum = 0 if max_length <= diff else max_length - diff

print(maximum)
print(minimum)