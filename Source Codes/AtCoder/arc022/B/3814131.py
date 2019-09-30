# ???????????

N = int(input())
A = list(map(int, input().split(" ")))

s = [0]*(max(A)+1)
l, r = 0, 0
max_num = 0
while r < N:
    if s[A[r]] == 0:
        s[A[r]] = 1
        r += 1
    else:
        s[A[l]] -= 1
        l += 1
    max_num = max(max_num, r-l)

print(max_num)