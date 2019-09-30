N, M = map(int, input().split())
A = [ int(x) for x in input().split() ]

B = [0]
sum_v = 0

for a in A:
    sum_v += a
    sum_v %= M
    B += [ sum_v ]

B.sort()
B += [ "@" ]

cur = B[0]
cnt, ans = 1, 0

for i, b in enumerate(B):
    if B[i+1] == "@":
        ans += cnt*(cnt-1)//2
        break

    if cur == B[i+1]:
        cnt += 1
    else:
        cur = B[i+1]
        ans += cnt*(cnt-1)//2
        cnt = 1

print(ans)