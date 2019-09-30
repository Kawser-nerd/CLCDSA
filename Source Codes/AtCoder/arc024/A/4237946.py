L, R = map(int, input().split())
inputs_l = [int(i) for i in input().split()]
inputs_r = [int(i) for i in input().split()]

def cal(one, other):
    global ans
    for item in one:
        if item in other:
            ans += 1
            other.remove(item)

ans = 0
if L < R:
    cal(inputs_l, inputs_r)
else:
    cal(inputs_r, inputs_l)

print(ans)