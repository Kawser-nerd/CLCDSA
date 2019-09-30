L,R = map(int,input().split())
l = list(map(int,input().split()))
r = list(map(int,input().split()))
left = [0] * 44
right = [0] * 44
for i in l:
    left[i] += 1
for i in r:
    right[i] += 1
res = 0
for i in range(44):
    res += min(left[i], right[i])
print(res)