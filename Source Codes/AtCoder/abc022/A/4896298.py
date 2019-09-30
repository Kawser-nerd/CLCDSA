n, s, t = map(int, input().split())
w = int(input())
a_array = []
for i in range(n-1):
    a_array.append(int(input()))
cnt = 1 if s <= w <= t else 0
for a in a_array:
    w += a
    if s <= w <= t:
        cnt += 1
print(cnt)