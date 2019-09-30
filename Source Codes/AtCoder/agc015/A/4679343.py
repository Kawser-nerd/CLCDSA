N, A, B = map(int, input().split())

if A > B:
    ans = 0
elif N==1:
    ans = 1 if A==B else 0
else:
    sum_min = (N-2) * A
    sum_max = (N-2) * B
    ans = sum_max - sum_min + 1

print(ans)