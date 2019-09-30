N, A, B = map(int, input().split())

if A > B:
    ans = 0
elif N==1:
    ans = 1 if A==B else 0
else:
    ans = (N-2) * (B-A) + 1

print(ans)