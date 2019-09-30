a, b, x = map(int, input().split())
check_b = b // x
# print(check_b)
check_a = (a-1) // x
# print(check_a)
ans = check_b - check_a
print(ans)