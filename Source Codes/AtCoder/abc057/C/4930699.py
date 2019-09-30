import math

num = int(input())
num_sqrt = int(math.sqrt(num))

ans = 11
for A in range(1, num_sqrt+1):
    if num % A == 0:
        B = int(num / A)
        A, B = str(A), str(B)
        now_ans = max(len(A), len(B))
        ans = min(ans, now_ans)
print(ans)