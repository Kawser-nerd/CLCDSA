A, B = map(int, input().split())
cnt = 0
for i in range(A, B+1):
    if str(i) == str(i)[::-1]:
        cnt += 1
print(cnt)