L, R = map(int, input().split())
inputs_l = [int(i) for i in input().split()]
inputs_r = [int(i) for i in input().split()]

def cal(one, other):
    ans = 0
    for item in one:
        if item in other:
            ans += 1
            other.remove(item)
    return ans

print(cal(inputs_l, inputs_r) if L < R else cal(inputs_r, inputs_l))