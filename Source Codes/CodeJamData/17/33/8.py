import math

CONVERT = 10000


def f(nums, power, k):
    # print(nums,power,k)
    for i in range(power):
        nums[nums.index(min(nums))] += 1

    ans = 1
    for n in nums:
        ans *=  n / CONVERT
    return ans



def logs(x):
    if x == 0:
        return -100000
    return math.log(x)

def logadd(a,b):
    if a < b:
        a,b = b,a
    return a + logs(1 + math.exp(b-a))


def p(nums, K):
    store = []
    for i in range(K+1):
        store.append([0] * len(nums))
    
    for k in range(K+1):
        for i in range(len(nums)):
            if k == 0:
                store[k][i] = 0
            elif i == 0:
                store[k][i] = -100000
            else:
                store[k][i] = logadd(store[k-1][i-1] +logs(nums[i]),store[k][i-1] + logs(1-nums[i]))
    return store[K][len(nums) - 1]

            



T = int(input())
for case in range(1, T+1):
    n,k = map(int, input().split())
    power = float(input())
    power *= CONVERT
    power = round(power)
    starts = list(map(float, input().split()))
    for i in range(len(starts)):
        starts[i] =round(starts[i] * CONVERT)
    ans = f(starts, power ,k)
    print("Case #%s: %s" % (case, ans))

