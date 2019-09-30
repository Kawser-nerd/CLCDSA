n = int(input())

ans = 0
for i in range(2, n+1):
    print("? {} {}".format(1, i))
    tmp = int(input())
    if tmp >= ans:
        v = i
        ans = tmp

for i in range(1, n+1):
    if i == v:
        continue
    else:
        print("? {} {}".format(v, i))
        ans = max(ans, int(input()))

print("! {}".format(ans))