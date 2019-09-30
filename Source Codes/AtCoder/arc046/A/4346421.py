import math
s = "123456789"

N = int(input())
ans = s[(N - 1) % 9] * math.ceil(N / 9)
print(ans)